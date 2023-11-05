#pragma once
#include <string>
#include <memory>
#include "Entity.h"

class Category: public Entity
{
	size_t id = SIZE_MAX, user_id= SIZE_MAX;
	std::string name;

	Category() = default;

public:
	Category(size_t user_id, std::string name);

	static std::unique_ptr<Category> create(const Category& cat);
	static std::unique_ptr<Category> getById(size_t id);
	static std::vector<std::unique_ptr<Category>> getByUserId(size_t user_id);
	// static std::unique_ptr<Category> getByName(size_t user_id, const std::string &name);
	


	size_t getId() const;

	size_t getUserId() const;
	Category& setUserId(size_t user_id);

	std::string getName() const;
	Category& setName(const std::string &name);

	void update() const;
	void remove() const;
	//void create() const;
	Category& operator=(const Category& x);

protected:
	// Inherited via Entity
	virtual const vector<std::string> getCreateField() const override;
	virtual const mysqlx::Row getCreateValues() const override;
	virtual vector<const Entity*> getChildren() const override;
	virtual std::string getTable() const override;
};

