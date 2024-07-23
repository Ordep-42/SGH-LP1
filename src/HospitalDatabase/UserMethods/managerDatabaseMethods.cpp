#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <iostream>
#include <string>

using namespace std;

void HospitalDatabase::createManager(Manager manager) {
    int returnCode = sqlite3_open("../data/hospital.db", &db);

    std::string sql = "INSERT INTO MANAGER (NAME, PASSWORD) VALUES (?, ?);";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (!verifyErrorCode())
        return;

    returnCode = sqlite3_bind_text(stmt, 1, manager.getName().c_str(), -1,
                                   SQLITE_STATIC);
    if (!verifyErrorCode()) {
        sqlite3_finalize(stmt);
        return;
    }

    returnCode = sqlite3_bind_text(stmt, 2, manager.getPassword().c_str(), -1,
                                   SQLITE_STATIC);
    if (!verifyErrorCode())
        return;

    returnCode = sqlite3_step(stmt);
    if (!verifyErrorCode())
        return;

    sqlite3_close(db);
}

void HospitalDatabase::listManagers() {
    returnCode = sqlite3_open("../data/hospital.db", &db);
    verifyErrorCode();
    std::string sql = "SELECT * FROM MANAGER;";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (!verifyErrorCode()) {
        return;
    }

    while ((returnCode = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *nome = sqlite3_column_text(stmt, 1);
        const unsigned char *password = sqlite3_column_text(stmt, 2);
        cout << id << ", " << nome << ", " << password << endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void HospitalDatabase::deleteManager(unsigned short managerId) {
    returnCode = sqlite3_open("../data/hospital.db", &db);
    if (!verifyErrorCode()) {
        return;
    }
    string sql = "DELETE FROM MANAGER WHERE ID = " + to_string(managerId) + ";";

    int returnCode = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (verifyErrorCode()) {
        cout << "Manager with ID = " << managerId << " deleted" << endl;
    }
    sqlite3_close(db);
}
