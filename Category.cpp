#include "Category.h"

Category::Category(size_t user_id, std::string name)
    : user_id(user_id), name(name)
{
}

std::unique_ptr<Category> Category::create(const Category& cat)
{
    std::unique_ptr<Category> category(new Category(cat));
    category->create_ent();
    return category;
}

std::unique_ptr<Category> Category::getById(size_t id)
{
    Category t;
    auto rows = t.select_ent({"user_id", "name"}, t.getTable(), "id = "+std::to_string(id), "id", 1);
    auto row = rows.fetchOne();
    std::unique_ptr<Category> res(new Category);
    res->id = id;
    res->user_id = row[0];
    res->name = row[1].operator std::string();
    return res;
}

std::vector<std::unique_ptr<Category>> Category::getByUserId(size_t user_id)
{
    Category t;
    auto rows = t.select_ent({ "id", "name" }, t.getTable(), "user_id = " + std::to_string(user_id), "id");
    std::vector<std::unique_ptr<Category>> res(rows.count());
    int i = 0;
    for (auto row : rows) {
        res[i].reset(new Category);
        res[i]->id = row[0];
        res[i]->user_id = user_id;
        res[i]->name = row[1].operator std::string();
        ++i;
    }
    return res;
}

size_t Category::getId() const
{
    return id;
}


size_t Category::getUserId() const
{
    return user_id;
}

Category& Category::setUserId(size_t user_id)
{
    this->user_id = user_id;
    addUpdate("user_id", user_id);
    return *this;
}

std::string Category::getName() const
{
    return name;
}

Category& Category::setName(const std::string &name)
{
    this->name = name;
    addUpdate("name", name);
    return *this;
}

void Category::update() const
{
    update_ent();
}

void Category::remove() const
{
    remove_ent();
}

Category& Category::operator=(const Category& x)
{
    return setName(x.getName());
}

//void Category::create() const
//{
//    create_ent();
//}

const vector<std::string> Category::getCreateField() const
{
    return vector<std::string>{"user_id", "name"};
}

const mysqlx::Row Category::getCreateValues() const
{
    return mysqlx::Row{user_id, name};
}

vector<const Entity*> Category::getChildren() const
{
    return vector<const Entity*>();
}

std::string Category::getTable() const
{
    return std::string();
}
