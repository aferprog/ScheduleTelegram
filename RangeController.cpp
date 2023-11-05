#include "RangeController.h"

void RangeController::ChangeRange(size_t id, const Range& info)
{
	//Range::findByDayInfoId();
}

void RangeController::AddRange(size_t id, const Range& info)
{
	Range::create(id, info.getBegin());
}
