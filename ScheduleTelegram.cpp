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
    
    // DataBase::initGlobalDB("mysqlx://root:root@127.0.0.1", "schedule");

    /*auto res = Week::getByUserId(13);

    for (auto& week : res) {
        week->remove();
    }*/

    const char* url = (argc > 1 ? argv[1] : "mysqlx://root:root@127.0.0.1");
    Session sess(url);
    Schema sch = sess.getSchema("schedule");
    Table table = sch.getTable("range");
    auto res = table.select("begin", "category_id").orderBy("id").execute();
    for (auto row : res) {
        auto t =row[0];
        cout << t<<endl;
    } 
    /*Row row;
    row.set(0, "12:00:00");
    row.set(1, 167);
    std::vector<std::string> f = { "begin", "day_info_id"};
    Result res = table.insert(f).values(row).execute();*/

    // cout << res.getAffectedItemsCount() << endl;
}
catch (const mysqlx::Error& err) {
    cout << "ERROR: " << err << '\n';
}