#include "Range.h"
#include "DataConverter.h"


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
    vector<unique_ptr<Range>> res(rows.count());
    int i = 0;
    for (const auto& row : rows) {
        res[i].reset(new Range);
        res[i]->id = row[0];
        res[i]->category_id = DataConverter::checkNull(row[1], SIZE_MAX);
        res[i]->begin = DataConverter::bytesToTime(row[2].getRawBytes());
        res[i]->action = DataConverter::checkNull<std::string>(row[3], "");
        res[i]->day_info_id = day_info_id;

        ++i;
    }

    return res;
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
    addUpdate("category_id", newCategoryId);
    return *this;
}

Range& Range::setBegin(const std::tm& newBegin) {
    begin = newBegin;
    
    addUpdate("begin", DataConverter::tmTimeToString(begin));
    return *this;
}

Range& Range::setAction(const std::string& newAction) {
    action = newAction;
    addUpdate("action", newAction);
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


    return mysqlx::Row{DataConverter::tmTimeToString(begin), day_info_id};

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
