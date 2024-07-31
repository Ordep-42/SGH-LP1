#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <iostream>
#include <optional>
#include <string>
#include <unistd.h>

using namespace std;

void HospitalDatabase::createManager(Manager manager) {
    int returnCode = sqlite3_open("../data/hospital.db", &db);

    std::string sql = "INSERT INTO MANAGER (NAME, PASSWORD) VALUES (?, ?);";

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, manager.getName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, manager.getPassword().c_str(), -1,
                      SQLITE_STATIC);

    sqlite3_step(stmt);
    sqlite3_close(db);
}

optional<Manager> HospitalDatabase::getManagerByID(int managerID) {
    int returnCode = sqlite3_open("../data/hospital.db", &db);

    std::string sql = "SELECT (ID ,NAME, PASSWORD) FROM MANAGER WHERE ID = ?;";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    returnCode = sqlite3_bind_int(stmt, 1, managerID);
    returnCode = sqlite3_step(stmt);
    if (returnCode == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);

        string name =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));

        string password =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));

        sqlite3_finalize(stmt);
        return Manager(id, name, password);
    } else if (returnCode == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    } else {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return std::nullopt;
    };
}

optional<Manager>
HospitalDatabase::getManagerByNameAndPassword(string name, string password) {

    int returnCode = sqlite3_open("../data/hospital.db", &db);

    std::string sql = "SELECT ID ,NAME, PASSWORD FROM MANAGER WHERE NAME = ? "
                      "AND PASSWORD = ?;";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (!verifyErrorCode()) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    }

    returnCode = sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    if (!verifyErrorCode()) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    }

    returnCode =
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    if (!verifyErrorCode()) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    }

    returnCode = sqlite3_step(stmt);

    if (returnCode == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);

        string name =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));

        string password =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));

        sqlite3_finalize(stmt);
        return Manager(id, name, password);
    } else if (returnCode == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    } else {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return std::nullopt;
    };
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
