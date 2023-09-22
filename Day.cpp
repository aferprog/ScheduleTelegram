#include "Day.h"

std::array<std::unique_ptr<Day>, 7> Day::findByWeekId(size_t week_id)
{
    return std::array<std::unique_ptr<Day>, 7>();
}

size_t Day::getId() const
{
    return id;
}
