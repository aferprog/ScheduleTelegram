#pragma once
#include <vector>
#include <memory>
#include "Range.h"
#include "Entity.h"
#include <array>

using std::string;


class Day: public Entity
{
	
	size_t week_id, day_info_id;
	std::vector<std::unique_ptr<Range>> ranges;

	Day() = default;

public:
	
	static std::array<std::unique_ptr<Day>, 7> findByWeekId(size_t week_id);

	virtual size_t getId() const override;
	size_t getWeekId() const;
	size_t getDayInfoId() const;
	
	const std::vector<std::unique_ptr<Range>>& getRanges() const;
	std::vector<std::unique_ptr<Range>>& getRanges();

};

