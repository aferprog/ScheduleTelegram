#include <iostream>
#include <mysqlx/xdevapi.h>
#include <memory>
#include "Week.h"
#include "DataBase.h"

using ::std::cout;
using ::std::endl;
using namespace ::mysqlx;

int main(int argc, const char* argv[])
try {
    DataBase::initGlobalDB("mysqlx://root:root@127.0.0.1", "schedule");

    auto res = Week::getByUserId(12);
    for (const auto& week : res) {
        cout << week->getId()<<endl;
    }

    /*const char* url = (argc > 1 ? argv[1] : "mysqlx://root:root@127.0.0.1");
    Session sess(url);
    Schema sch = sess.getSchema("schedule");
    Table table = sch.getTable("week");
    auto res = table.select("id", "user_id").limit(10).execute();
    for (auto t : res) {
        cout << t[0] << ' ' << t[1];
    }*/
    /*Row row;
    row.set(0, 222u);
    std::vector<std::string> f = { "user_id" };
    Result res = table.insert(f).values(row).execute();
    cout << res.getAutoIncrementValue() << endl;
    cout << "Done!" << endl;*/
}
catch (const mysqlx::Error& err) {
    cout << "ERROR: " << err << '\n';
}