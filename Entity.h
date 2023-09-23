#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <mysqlx/xdevapi.h>

using std::string;
using std::vector;

class Entity
{
	friend class DataBase;

protected:
	vector<std::string> update_fields;
	mysqlx::Row update_values;

	size_t id;

	virtual void update_ent() const;
	virtual void remove_ent() const;
	virtual void create_ent() const;
	virtual mysqlx::RowResult select_ent(std::vector<std::string> fields, std::string table, std::string condition="", std::string order="", size_t limit = SIZE_MAX) const;

	virtual const vector<std::string> getUpdateFields() const;
	virtual const mysqlx::Row GetUpdateRow() const;

	virtual const vector<std::string> getCreateField() const = 0;
	virtual const mysqlx::Row getCreateValues() const = 0;

	virtual vector<const Entity*> getChildren() const = 0;

public:

	virtual std::string getTable() const = 0;
	virtual size_t getId() const = 0;
	virtual void update() const=0;
	virtual void remove() const=0;

};

