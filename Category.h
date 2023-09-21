#pragma once
#include <string>
class Category
{
	size_t id, user_id;
	std::string name;
public:

	size_t getId() const;
	size_t getUserId() const;
	std::string getName() const;
	Category& setName(std::string name);

	void update() const;
	void remove() const;
};

