#pragma once
#include <mysqlx/xdevapi.h>
#include "IEntity.h"

class DataBase
{
public:
	DataBase(string url);
	void updateEntity(const IEntity* ent) const;
	void removeEntity(const IEntity* ent) const;
	void createEntity(const IEntity* ent) const;
};

