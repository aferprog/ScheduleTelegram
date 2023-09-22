#include "IEntity.h"
#include "DataBase.h"

extern BDPointer db;

void IEntity::update() const
{
	db->updateEntity(this);
}

void IEntity::remove() const
{
	db->removeEntity(this);
}

void IEntity::create_ent() const
{
	db->createEntity(this);
}
