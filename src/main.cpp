#include <iostream>
#include <ostream>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    char *errMsg = 0;

    int rc = sqlite3_open("../data/test.db", &db);

    if (rc) {
        std::cerr << "Cant open db: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened db sucessfuly" << std::endl;
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS HOSPITAL("
                      "ID INT PRIMARY KEY NOT NULL,"
                      "NAME TEXT NOT NULL,"
                      "AGE INT NOT NULL,"
                      "ADDRESS CHAR(50),"
                      "SALARY REAL );";

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
    } else {
        std::cout << "Table created successfully" << std::endl;
    }

    return 0;
}