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
    size_t category_id, day_info_id;
    std::tm begin;
    std::string action;
    std::unique_ptr<Category> category;

    Range(size_t day_info_id, std::tm begin);
    Range() = default;

public:
    // static unique_ptr<Range> findById(size_t id);
    static vector<unique_ptr<Range>> findByDayInfoId(size_t day_info_id);

    size_t getId() const override;
    size_t getCategoryId() const;
    const std::tm& getBegin() const;
    const std::string& getAction() const;
    const size_t getDayInfoId() const;

    Range& setCategoryId(size_t newCategoryId);
    Range& setBegin(const std::tm& newBegin);
    Range& setAction(const std::string& newAction);

    const std::unique_ptr<Category>& getCategory() const;
    std::unique_ptr<Category>& getCategory();

    virtual void update() const override;
    virtual void remove() const override;

    virtual std::string getTable() const override;
protected:
    // Inherited via Entity
    virtual const vector<std::string> getCreateField() const override;
    virtual const mysqlx::Row getCreateValues() const override;
    virtual vector<const Entity*> getChildren() const override;
};