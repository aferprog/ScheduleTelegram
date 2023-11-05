#include "WeekController.h"

void WeekController::AddWeek(size_t user_id) const
{
	Week::create(user_id);
}

void WeekController::RemoveWeek(size_t user_id, int number) const
{
	Week::getByUserId(user_id)[number]->remove();
}
