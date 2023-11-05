#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <mysqlx/xdevapi.h>

using std::string;
using std::vector;

class Entity
{
	friend class DataBase;
	vector<std::string> update_fields;
	mysqlx::Row update_values;

protected:
	size_t id = SIZE_MAX;
	virtual mysqlx::RowResult select_ent(std::vector<std::string> fields, std::string table, std::string condition="", std::string order="", size_t limit = SIZE_MAX) const;


	virtual void update_ent() const;
	virtual void remove_ent() const;
	virtual void create_ent() const;

	virtual const vector<std::string> getUpdateFields() const;
	virtual const mysqlx::Row GetUpdateRow() const;

	template<typename ValueType>
	void addUpdate(std::string field, ValueType value);

	virtual const vector<std::string> getCreateField() const = 0;
	virtual const mysqlx::Row getCreateValues() const = 0;

	virtual vector<const Entity*> getChildren() const = 0;

public:

	virtual std::string getTable() const = 0;
	virtual size_t getId() const = 0;
	virtual void update() const=0;
	virtual void remove() const=0;

};

template<typename ValueType>
inline void Entity::addUpdate(std::string field, ValueType value)
{
	auto it = std::find(update_fields.begin(), update_fields.end(), field);
	if (it == update_fields.end()) {
		update_fields.push_back(field);
		update_values[update_fields.size() - 1] = value;
	}
	else {
		update_values[it-update_fields.begin()]=value;
	}
}
