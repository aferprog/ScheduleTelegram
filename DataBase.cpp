#include "DataBase.h"

BDPointer db = nullptr;

mysqlx::Table DataBase::getTable(string table_name) const
{
	return session->getSchema(schema).getTable(table_name);
}

void DataBase::initGlobalDB(string url, string schema)
{
	db = std::make_unique<DataBase>(url, schema);
}

DataBase::DataBase(string url, string schema)
{
	session = std::make_unique<mysqlx::Session>(url);
	this->schema = schema;
}

void DataBase::updateEntity(const IEntity* ent) const
{
	
	auto query = getTable(ent->getTable()).update();
	auto fields = ent->getUpdateFields();
	if (!fields.empty()) {
		auto values = ent->GetUpdateRow();
		for (size_t i = 0; i < fields.size(); ++i)
			query.set(fields[i], values[i]);
		query.where("id=" + std::to_string(ent->getId()));
		query.limit(1u);
		auto res = query.execute();
	}

	for (const auto* child : ent->getChildren())
		updateEntity(child);
}

void DataBase::removeEntity(const IEntity* ent) const
{
	auto query = getTable(ent->getTable()).remove();
	query.where("id=" + std::to_string(ent->getId()));
	auto res = query.execute();
	
}

void DataBase::createEntity(const IEntity* ent) const
{
	auto table = getTable(ent->getTable());
	auto res = table.insert(ent->getCreateField()).values(ent->getCreateValues()).execute();
	
	const_cast<IEntity*>(ent)->id = res.getAutoIncrementValue();
}
