#pragma once
#include <memory>
#include <vector>
#include "Day.h"
#include <array>
#include "IEntity.h"

class Week : public IEntity
{
	//size_t id=-1;
	size_t user_id = -1;
	std::array<std::unique_ptr<Day>, 7> days;

	Week(size_t user_id);

public:
	static std::vector<std::unique_ptr<Week>> getByUserId(size_t user_id);
	static std::unique_ptr<Week> create(size_t user_id);
	size_t getId() const;
	size_t getUserId() const;

	const std::array<std::unique_ptr<Day>, 7>& getDays() const;
	std::array<std::unique_ptr<Day>, 7>& getDays();

	void update() const;
	void remove() const;

	// Inherited via IEntity
	virtual string getTable() const override;
	virtual vector<string> getUpdateFields() const override;
	virtual mysqlx::Row GetUpdateRow() const override;
	virtual vector<const IEntity*> getChildren() const override;

	// Inherited via IEntity
	virtual vector<string> getCreateField() const override;
	virtual mysqlx::Row getCreateValues() const override;
};

