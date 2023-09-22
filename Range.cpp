#include "Range.h"


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
    // TODO: insert return statement here
    return category;
}
