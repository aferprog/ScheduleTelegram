#include "DayExtra.h"

inline size_t DayExtra::getUserId() const { return user_id; }

inline size_t DayExtra::getDayInfoId() const { return day_info_id; }

inline const std::tm& DayExtra::getDate() const { return date; }

inline DayExtra& DayExtra::setDate(std::tm date) {
	this->date = date;
	return *this; 
}

inline const std::vector<std::unique_ptr<Range>>& DayExtra::getRanges() const { return ranges; }

inline std::vector<std::unique_ptr<Range>>& DayExtra::getRanges() { return ranges; }
