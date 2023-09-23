#pragma once
#include <string>
#include <ctime>
#include "Category.h"
#include <memory>
#include <vector>
#include "Entity.h"

using std::unique_ptr;
using std::vector;

class Range: public Entity {
private:
    size_t id;
    size_t category_id;
    std::tm begin;
    std::string action;
    std::unique_ptr<Category> category;

public:
    static unique_ptr<Range> findById(size_t id);
    static vector<unique_ptr<Range>> findByDayInfoId(size_t day_info_id);

    size_t getId() const;
    size_t getCategoryId() const;
    const std::tm& getBegin() const;
    const std::string& getAction() const;

    Range& setCategoryId(size_t newCategoryId);
    Range& setBegin(const std::tm& newBegin);
    Range& setAction(const std::string& newAction);

    const std::unique_ptr<Category>& getCategory() const;
    std::unique_ptr<Category>& getCategory();
};