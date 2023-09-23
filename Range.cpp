#include "Range.h"


Range::Range(size_t day_info_id, std::tm begin)
    :day_info_id(day_info_id), begin(begin)
{
}
//
//unique_ptr<Range> Range::findById(size_t id)
//{
//    Range t;
//    t.create_ent();
//    return unique_ptr<Range>();
//}

vector<unique_ptr<Range>> Range::findByDayInfoId(size_t day_info_id)
{
    Range t;
    auto rows = t.select_ent({ "id", "categoty_id", "begin", "action" }, t.getTable(),
        "day_info_id=" + std::to_string(day_info_id), "begin"
    );
    return vector<unique_ptr<Range>>();
}

size_t Range::getId() const {
    return id;
}

size_t Range::getCategoryId() const {
    return category_id;
}

const std::tm& Range::getBegin() const {
    return begin;
}

const std::string& Range::getAction() const {
    return action;
}

const size_t Range::getDayInfoId() const
{

    return day_info_id;
}

Range& Range::setCategoryId(size_t newCategoryId) {
    category_id = newCategoryId;
    return *this;
}

Range& Range::setBegin(const std::tm& newBegin) {
    begin = newBegin;
    return *this;
}

Range& Range::setAction(const std::string& newAction) {
    action = newAction;
    return *this;
}

const std::unique_ptr<Category>& Range::getCategory() const
{
    return category;
}

std::unique_ptr<Category>& Range::getCategory()
{
    return category;
}

const vector<std::string> Range::getCreateField() const
{
    return vector<std::string>{"begin", "day_info_id"};
}

const mysqlx::Row Range::getCreateValues() const
{

    using std::to_string;

    return mysqlx::Row{
        to_string(begin.tm_hour)+":"+ to_string(begin.tm_min)+":"+ to_string(begin.tm_sec), 
        day_info_id
    };

}

vector<const Entity*> Range::getChildren() const
{
    return vector<const Entity*> {category.get()};
}

std::string Range::getTable() const
{
    return "range";
}

void Range::update() const
{
    update_ent();
}

void Range::remove() const
{
    remove_ent();
}
