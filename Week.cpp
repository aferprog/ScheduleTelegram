#include "Week.h"



Week::Week(size_t user_id): user_id(user_id){

}

std::vector<std::unique_ptr<Week>> Week::getByUserId(size_t user_id)
{
    return std::vector<std::unique_ptr<Week>>();
}

std::unique_ptr<Week> Week::create(size_t user_id)
{
    std::unique_ptr<Week> week(new Week(user_id));
    week->create_ent();
    return week;
}

size_t Week::getId() const
{
    return id;
}

size_t Week::getUserId() const
{
    return user_id;
}

const std::array<std::unique_ptr<Day>, 7>& Week::getDays() const
{
    return days;
}

std::array<std::unique_ptr<Day>, 7>& Week::getDays()
{
    return days;
}


string Week::getTable() const
{
    return "week";
}

vector<const Entity*> Week::getChildren() const
{
    vector<const Entity*> res(7);
    for (int i = 0; i < 7; ++i)
        res[i] = static_cast<const Entity*> (days[i].get());
    return res;
}

const vector<string> Week::getCreateField() const
{
    return vector<string>{"user_id"};
}

const mysqlx::Row Week::getCreateValues() const
{
    mysqlx::Row row;
    row[0] = user_id;
    return row;
}

void Week::update() const
{
    update_ent();
}

void Week::remove() const
{
    remove_ent();
}



