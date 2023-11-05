#pragma once
#include "Range.h"
class RangeController
{
public:
	void ChangeRange(size_t id, const Range &info);
	void AddRange(size_t id, const Range& info);
};

