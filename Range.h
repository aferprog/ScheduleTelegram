#pragma once
#include <string>
#include <ctime>
#include "Category.h"
#include <memory>

//using namespace std;

class Range {
private:
    size_t id;
    size_t category_id;
    std::tm begin;
    std::string action;
    std::unique_ptr<Category> category;

public:
    Range() = default;

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