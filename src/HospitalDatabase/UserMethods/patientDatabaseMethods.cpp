#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <iostream>
#include <string>

void HospitalDatabase::createPatient(User patient) {
    returnCode = sqlite3_open("../data/hospital.db", &db);

    string sql = "INSERT INTO PATIENT (NAME, PASSWORD) VALUES (?, ?);";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (!verifyErrorCode()) {
        sqlite3_close(db);
        return;
    }
    returnCode = sqlite3_bind_text(stmt, 1, patient.getName().c_str(), -1,
                                   SQLITE_STATIC);
    if (!verifyErrorCode()) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    returnCode = sqlite3_bind_text(stmt, 2, patient.getPassword().c_str(), -1,
                                   SQLITE_STATIC);
    if (!verifyErrorCode()) {
        sqlite3_close(db);
        return;
    }
    returnCode = sqlite3_step(stmt);

    sqlite3_close(db);
}

void HospitalDatabase::listPatients() {
    returnCode = sqlite3_open("../data/hospital.db", &db);
    if (!verifyErrorCode()) {
        return;
    }

    std::string sql = "SELECT * FROM PATIENT;";

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

void HospitalDatabase::deletePatient(unsigned short patientId) {
    returnCode = sqlite3_open("../data/hospital.db", &db);
    if (!verifyErrorCode()) {
        return;
    }
    string sql = "DELETE FROM PATIENT WHERE ID = " + to_string(patientId) + ";";

    int returnCode = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (verifyErrorCode()) {
        cout << "Patient with ID = " << patientId << " deleted" << endl;
    }
}
