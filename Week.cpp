#include "Week.h"


Week::Week(size_t user_id): user_id(user_id){

}

std::vector<std::unique_ptr<Week>> Week::getByUserId(size_t user_id)
{
    return std::vector<std::unique_ptr<Week>>();
}

std::unique_ptr<Week> Week::create(size_t user_id)
{
    Week* week = new Week(user_id);



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

void Week::update() const
{
}

void Week::remove() const
{
}
