#include "DataConverter.h"

std::tm DataConverter::bytesToTime(const mysqlx::bytes &bytes)
{
    std::tm res;
    res.tm_hour = 0;
    res.tm_min = 0;
    res.tm_sec = 0;
    if (bytes.length() > 0)
        res.tm_hour = (int)*(bytes.begin()+1);
    if (bytes.length() > 1)
        res.tm_min = (int)*(bytes.begin() + 2);
    if (bytes.length() > 2)
        res.tm_sec = (int)*(bytes.begin() + 3);

    return res;
}

std::string DataConverter::tmTimeToString(const std::tm &time)
{
    using std::to_string;
    return to_string(time.tm_hour) + ":" + to_string(time.tm_min) + ":" + to_string(time.tm_sec);
}
