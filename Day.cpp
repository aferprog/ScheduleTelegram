#include "Day.h"

std::array<std::unique_ptr<Day>, 7> Day::findByWeekId(size_t week_id)
{
    std::array<std::unique_ptr<Day>, 7> test;
    return test;
}

size_t Day::getId() const
{
    return id;
}

string Day::getTable() const
{
    return string();
}

vector<const Entity*> Day::getChildren() const
{
    return vector<const Entity*>();
}

const vector<std::string> Day::getCreateField() const
{
    return vector<std::string>();
}

const mysqlx::Row Day::getCreateValues() const
{
    return mysqlx::Row();
}
