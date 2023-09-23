#pragma once
#include <memory>
#include <vector>
#include "Day.h"
#include <array>
#include "Entity.h"

class Week : public Entity
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

	virtual void update() const override;
	virtual void remove() const override;
	virtual std::string getTable() const override;

protected:
	virtual vector<const Entity*> getChildren() const override;

	virtual const vector<std::string> getCreateField() const override;

	virtual const mysqlx::Row getCreateValues() const override;

};
