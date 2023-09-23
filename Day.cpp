#include "Day.h"

std::array<std::unique_ptr<Day>, 7> Day::findByWeekId(size_t week_id)
{
    Day t;
    auto rows = t.select_ent({ "id", "week_id", "day_info_id",}, t.getTable(), "week_id="+std::to_string(week_id), "id", 7);
    if (rows.count() != 7)
        throw 1;
    std::array<std::unique_ptr<Day>, 7> res;
    int i = 0;
    for (const auto& row : rows) {
        res[i].reset(new Day());
        res[i]->id = row[0];
        res[i]->week_id = row[1];
        res[i]->day_info_id = row[2];
        i++;
    }
    return res;
}

size_t Day::getId() const
{
    return id;
}

size_t Day::getWeekId() const
{
    return week_id;
}

size_t Day::getDayInfoId() const
{
    return day_info_id;
}

const std::vector<std::unique_ptr<Range>>& Day::getRanges() const
{
    return ranges;
}

std::vector<std::unique_ptr<Range>>& Day::getRanges()
{
    return ranges;
}

const vector<std::string> Day::getCreateField() const
{
    throw 1;
}

const mysqlx::Row Day::getCreateValues() const
{
    throw 1;
}

vector<const Entity*> Day::getChildren() const
{
    vector<const Entity*> res(ranges.size());
    for (int i = 0; i < res.size(); ++i)
        res[i] = static_cast<const Entity*> (ranges[i].get());
    return res;
}

std::string Day::getTable() const
{
    return "day";
}

void Day::update() const
{
    throw 1;
}

void Day::remove() const
{
    throw 1;
}
