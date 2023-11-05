#pragma once
#include <ctime>
#include <mysqlx/xdevapi.h>
class DataConverter
{
public:
	static std::tm bytesToTime(const mysqlx::bytes &bytes);
	static std::tm bytesToDate(const mysqlx::bytes& bytes);

	static std::string tmDateToString(const std::tm& date);
	static std::string tmTimeToString(const std::tm &time);
	
	template<typename ValueType>
	static ValueType checkNull(const mysqlx::Value &val, const ValueType &ifNull/*, ValueType* output = nullptr*/);
};

template<typename ValueType>
inline ValueType DataConverter::checkNull(const mysqlx::Value& val, const ValueType& ifNull/*, ValueType* output*/)
{
	if (val.isNull())
		return ifNull;

	//ValueType *t;
	//if (!output)
	//	output = &t;

	//if (std::is_same<std::string, ValueType>())
	//	return val.operator mysqlx::abi2::r0::string;
	return val;
}
