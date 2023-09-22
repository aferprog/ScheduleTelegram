#pragma once
#include <vector>
#include <memory>
#include "Range.h"
#include "IEntity.h"

using std::string;


class Day: public IEntity
{
	
	size_t id, week_id, day_info_id;

	std::vector<std::unique_ptr<Range>> ranges;

	Day() = default;

public:
	
	static std::array<std::unique_ptr<Day>, 7> findByWeekId(size_t week_id);
	// static std::unique_ptr<Day> create();

	virtual size_t getId() const override;
	size_t getWeekId() const;
	size_t getDayInfoId() const;

	void update() const;
	void remove() const;

	const std::vector<std::unique_ptr<Range>>& getRanges() const;
	std::vector<std::unique_ptr<Range>>& getRanges();

	// Inherited via IEntity
	virtual string getTable() const override;
	virtual vector<string> getUpdateFields() const override;
	virtual mysqlx::Row GetUpdateRow() const override;
	virtual vector<const IEntity*> getChildren() const override;
};

