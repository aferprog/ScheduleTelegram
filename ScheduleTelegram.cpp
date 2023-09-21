#include <iostream>
#include <mysqlx/xdevapi.h>
#include <memory>

using ::std::cout;
using ::std::endl;
using namespace ::mysqlx;

class Test {
public:
    int t = 0;
    Test() {
        puts("Constr");
    }
    ~Test() {
        puts("Destr");
    }
};

int main(int argc, const char* argv[])
try {
    auto ptr = std::make_unique<Test>();
    
    {
        auto& t = ptr;
        t->t = 77;
    }
    cout << ptr->t;


   /* const char* url = (argc > 1 ? argv[1] : "mysqlx://root:root@127.0.0.1");
    Session sess(url);
    
    Schema sch = sess.getSchema("schedule");
    Table table = sch.getTable("week");
    auto res = sess.sql("").execute();
    res.fetchOne().;
    /*for (auto t : res) {
        cout << t[0] << ' ' << t[1];
    }*/
    //res.getColumns
    /*Row row;
    row.set(0, 777u);
    Result res = table.insert("user_id").values(row).execute();
    cout<< res.getAffectedItemsCount()<< endl;
    cout << "Done!" << endl;*/
}
catch (const mysqlx::Error& err) {
    cout << "ERROR: " << err << '\n';
}