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

void DataBase::updateEntity(const Entity* ent) const
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

void DataBase::removeEntity(const Entity* ent) const
{
	auto query = getTable(ent->getTable()).remove();
	query.where("id=" + std::to_string(ent->getId()));
	auto res = query.execute();
	
}

void DataBase::createEntity(const Entity* ent) const
{
	auto table = getTable(ent->getTable());
	auto res = table.insert(ent->getCreateField()).values(ent->getCreateValues()).execute();
	
	const_cast<Entity*>(ent)->id = res.getAutoIncrementValue();
}

mysqlx::RowResult DataBase::selectEntity(std::vector<std::string> fields, std::string table, std::string condition, std::string order, size_t limit) const
{
	auto query = getTable(table).select(fields);
	if (!condition.empty())
		query.where(condition);
	if (!order.empty())
		query.orderBy(order);
	if (limit != SIZE_MAX)
		query.limit(limit);

	return query.execute();
}
