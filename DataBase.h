#pragma once
#include <mysqlx/xdevapi.h>
#include "IEntity.h"
#include <memory>


class DataBase
{
	std::unique_ptr<mysqlx::Session> session = nullptr;
	string schema;

	mysqlx::Table getTable(string table_name) const;
	
public:
	static void initGlobalDB(string url, string schema);
	DataBase(string url, string schema);

	void updateEntity(const IEntity* ent) const;
	void removeEntity(const IEntity* ent) const;
	void createEntity(const IEntity* ent) const;
};

using BDPointer = std::unique_ptr<DataBase>;

