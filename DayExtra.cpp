#include "DayExtra.h"

inline size_t DayExtra::getUserId() const { 
	return user_id; 
}

inline size_t DayExtra::getDayInfoId() const { 
	return day_info_id; 
}

inline const std::tm& DayExtra::getDate() const { 
	return date; 
}

inline DayExtra& DayExtra::setDate(std::tm date) {
	
	this->date = date;
	return *this; 
}

inline const std::vector<std::unique_ptr<Range>>& DayExtra::getRanges() const { 
	return ranges;
}

inline std::vector<std::unique_ptr<Range>>& DayExtra::getRanges() { return ranges; }

const vector<std::string> DayExtra::getCreateField() const
{
	return vector<std::string>();
}

const mysqlx::Row DayExtra::getCreateValues() const
{
	return mysqlx::Row();
}

vector<const Entity*> DayExtra::getChildren() const
{
	return vector<const Entity*>();
}

std::string DayExtra::getTable() const
{
	return std::string();
}

size_t DayExtra::getId() const
{
	return size_t();
}

void DayExtra::update() const
{
}

void DayExtra::remove() const
{
}
