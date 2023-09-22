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

vector<string> Day::getUpdateFields() const
{
    return vector<string>();
}

mysqlx::Row Day::GetUpdateRow() const
{
    return mysqlx::Row();
}

vector<const IEntity*> Day::getChildren() const
{
    return vector<const IEntity*>();
}
