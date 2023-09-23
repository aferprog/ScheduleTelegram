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

    mysqlx::Row source;

    source[0] = 1;
    source[1] = "test";


    mysqlx::Row target = std::move(source);

    cout << source.colCount()<<endl;
    cout << target.colCount() << endl;

    /*DataBase::initGlobalDB("mysqlx://root:root@127.0.0.1", "schedule");
    auto week = Week::create(212);
    cout<< week->getId()<<endl;

    week->remove();*/

    // week->getDays()[1];
    // week->update();


    /*const char* url = (argc > 1 ? argv[1] : "mysqlx://root:root@127.0.0.1");
    Session sess(url);

    Schema sch = sess.getSchema("schedule");
    Table table = sch.getTable("week");
    // auto res = sess.sql("").execute();
    // res.fetchOne().;
    /*for (auto t : res) {
        cout << t[0] << ' ' << t[1];
    }*/
    //res.getColumns
   /* Row row;
    row.set(0, 222u);
    std::vector<std::string> f = { "user_id" };
    Result res = table.insert(f).values(row).execute();
    cout << res.getAutoIncrementValue() << endl;
    cout << "Done!" << endl;*/
}
catch (const mysqlx::Error& err) {
    cout << "ERROR: " << err << '\n';
}