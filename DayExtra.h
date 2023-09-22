#pragma once
#include <ctime>
#include <vector>
#include <memory>
#include "Range.h"

class DayExtra
{
	size_t user_id, day_info_id;
	std::tm date;

	std::vector<std::unique_ptr<Range>> ranges;
public: 

    size_t getUserId() const;
    size_t getDayInfoId() const;
    const std::tm& getDate() const;
    DayExtra& setDate(std::tm date);

    const std::vector<std::unique_ptr<Range>>& getRanges() const;
    std::vector<std::unique_ptr<Range>>& getRanges();

};

