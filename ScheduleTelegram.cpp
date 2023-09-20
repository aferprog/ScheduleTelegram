#include <iostream>
#include <mysqlx/xdevapi.h>

using ::std::cout;
using ::std::endl;
using namespace ::mysqlx;



int main(int argc, const char* argv[])
try {

    const char* url = (argc > 1 ? argv[1] : "mysqlx://root:root@127.0.0.1");
    Session sess(url);

    Schema sch = sess.getSchema("schedule");
    Table table = sch.getTable("week");
    Row row;
    row.set(0, 777u);
    Result res = table.insert("user_id").values(row).execute();
    cout<< res.getAffectedItemsCount()<< endl;
    cout << "Done!" << endl;
}
catch (const mysqlx::Error& err) {
    cout << "ERROR: " << err << '\n';
}