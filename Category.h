#pragma once
#include <string>
#include "Entity.h"

class Category: public Entity
{
	size_t id, user_id;
	std::string name;
public:

	Category() = default;

	size_t getId() const;
	size_t getUserId() const;
	std::string getName() const;
	Category& setName(std::string name);

	void update() const;
	void remove() const;
};

