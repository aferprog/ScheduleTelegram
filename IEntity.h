#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <mysqlx/xdevapi.h>

using std::string;
using std::vector;

class IEntity
{
public:
	virtual string getTable() const = 0;
	virtual vector<string> getUpdateFields() const = 0;
	virtual mysqlx::Row GetUpdateRow() const = 0;

	virtual vector<const IEntity*> getChildren() const = 0;

	virtual size_t getId() const = 0;
};

