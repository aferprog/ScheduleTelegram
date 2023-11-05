#pragma once
#include "Week.h"
class WeekController
{
public:
	void AddWeek(size_t user_id) const;
	void RemoveWeek(size_t user_id, int number) const;
	// void Reorder();
};

