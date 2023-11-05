#pragma once
#include <ctime>
#include <vector>
#include <memory>
#include "Range.h"
#include "Entity.h"

class DayExtra: public Entity
{
	size_t user_id = SIZE_MAX, day_info_id= SIZE_MAX;
	std::tm date;

	std::vector<std::unique_ptr<Range>> ranges;
public: 

    size_t getUserId() const;
    size_t getDayInfoId() const;
    const std::tm& getDate() const;
    DayExtra& setDate(std::tm date);

    const std::vector<std::unique_ptr<Range>>& getRanges() const;
    std::vector<std::unique_ptr<Range>>& getRanges();

    virtual std::string getTable() const override;
    virtual size_t getId() const override;
    virtual void update() const override;
    virtual void remove() const override;

protected:
    // Inherited via Entity
    virtual const vector<std::string> getCreateField() const override;
    virtual const mysqlx::Row getCreateValues() const override;
    virtual vector<const Entity*> getChildren() const override;
};

