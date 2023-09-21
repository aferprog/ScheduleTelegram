#pragma once
#include <vector>
#include <memory>
#include "Range.h"

class Day
{
	
	size_t id, week_id, day_info_id;

	std::vector<std::unique_ptr<Range>> ranges;

	Day() = default;

public:
	
	static std::array<std::unique_ptr<Day>, 7> findByWeekId(size_t week_id);
	static std::unique_ptr<Day> create();

	size_t getId() const;
	size_t getWeekId() const;
	size_t getDayInfoId() const;

	void update() const;
	void remove() const;

	const std::vector<std::unique_ptr<Range>>& getRanges() const;
	std::vector<std::unique_ptr<Range>>& getRanges();
};

