#include "Entity.h"
#include "DataBase.h"

extern BDPointer db;

void Entity::update_ent() const
{
	db->updateEntity(this);
}

void Entity::remove_ent() const
{
	db->removeEntity(this);
}

void Entity::create_ent() const
{
	db->createEntity(this);
}

mysqlx::RowResult Entity::select_ent(std::vector<std::string> fields, std::string table, std::string condition, std::string order, size_t limit) const
{
	return db->selectEntity(fields, table, condition, order, limit);
}

const vector<std::string> Entity::getUpdateFields() const
{
	auto res = std::move(const_cast<Entity*>(this)->update_fields);
	return res;
}

const mysqlx::Row Entity::GetUpdateRow() const
{
	mysqlx::Row res = std::move(const_cast<Entity*>(this)->update_values);
	return res;
}
