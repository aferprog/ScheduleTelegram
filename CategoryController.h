#pragma once
#include "Category.h"

class CategoryController
{
public:
	void addCategory(const Category& cat);
	void changeCategory(size_t id, const Category& cat);
};

