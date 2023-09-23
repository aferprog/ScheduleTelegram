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

const vector<std::string> Entity::getUpdateFields() const
{
	auto res = std::move(update_fields);
	return res;
}

const mysqlx::Row Entity::GetUpdateRow() const
{
	mysqlx::Row res = std::move(update_values);
	return res;
}
