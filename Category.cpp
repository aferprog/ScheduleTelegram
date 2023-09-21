#include "Category.h"

size_t Category::getId() const
{
    return id;
}

size_t Category::getUserId() const
{
    return user_id;
}

std::string Category::getName() const
{
    return name;
}

Category& Category::setName(std::string name)
{
    this->name = name;
    return *this;
}

void Category::update() const
{
}

void Category::remove() const
{
}
