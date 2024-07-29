#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <iostream>
#include <string>

void HospitalDatabase::createAttendant(User attendant) {
    returnCode = sqlite3_open("../data/hospital.db", &db);

    string sql = "INSERT INTO ATTENDANT (NAME, PASSWORD) VALUES (?, ?);";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (!verifyErrorCode()) {
        cout << "Preparation failed\n";
        sqlite3_close(db);
        return;
    }

    returnCode = sqlite3_bind_text(stmt, 1, attendant.getName().c_str(), -1,
                                   SQLITE_STATIC);
    if (!verifyErrorCode()) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    returnCode = sqlite3_bind_text(stmt, 2, attendant.getPassword().c_str(), -1,
                                   SQLITE_STATIC);
    if (!verifyErrorCode()) {
        sqlite3_close(db);
        return;
    }

    returnCode = sqlite3_step(stmt);

    sqlite3_close(db);
}

void HospitalDatabase::listAttendants() {
    returnCode = sqlite3_open("../data/hospital.db", &db);
    if (!verifyErrorCode()) {
        return;
    }

    std::string sql = "SELECT * FROM ATTENDANT;";

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

void HospitalDatabase::deleteAttendant(unsigned short attendantId) {
    returnCode = sqlite3_open("../data/hospital.db", &db);
    if (!verifyErrorCode()) {
        return;
    }
    string sql =
        "DELETE FROM ATTENDANT WHERE ID = " + to_string(attendantId) + ";";

    int returnCode = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (verifyErrorCode()) {
        cout << "Attendant with ID = " << attendantId << " deleted" << endl;
    }
}
