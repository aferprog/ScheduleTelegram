#pragma once
#include <mysqlx/xdevapi.h>
#include "Entity.h"
#include <memory>


class DataBase
{
	std::unique_ptr<mysqlx::Session> session = nullptr;
	std::string schema;

	mysqlx::Table getTable(std::string table_name) const;
	
public:
	static void initGlobalDB(std::string url, std::string schema);
	DataBase(std::string url, std::string schema);

	void updateEntity(const Entity* ent) const;
	void removeEntity(const Entity* ent) const;
	void createEntity(const Entity* ent) const;

	mysqlx::RowResult selectEntity(std::vector<std::string> fields, std::string table, std::string condition="", std::string order = "", size_t limit = SIZE_MAX) const;
};

using BDPointer = std::unique_ptr<DataBase>;

