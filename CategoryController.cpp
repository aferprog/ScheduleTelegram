#include "CategoryController.h"

void CategoryController::addCategory(const Category& cat)
{
	Category::create(cat);
}

void CategoryController::changeCategory(size_t id, const Category& cat)
{
	auto x = Category::getById(id);
	*x = cat;
	x->update();
}
