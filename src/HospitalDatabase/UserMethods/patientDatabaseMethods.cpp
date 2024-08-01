#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <iostream>
#include <string>

void HospitalDatabase::createPatient(User patient) {
    returnCode = sqlite3_open("../data/hospital.db", &db);

    string sql = "INSERT INTO PATIENT (NAME, PASSWORD) VALUES (?, ?);";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    returnCode = sqlite3_bind_text(stmt, 1, patient.getName().c_str(), -1,
                                   SQLITE_STATIC);
    returnCode = sqlite3_bind_text(stmt, 2, patient.getPassword().c_str(), -1,
                                   SQLITE_STATIC);
    returnCode = sqlite3_step(stmt);

    sqlite3_close(db);
}

optional<Patient> HospitalDatabase::getPatientByID(int patientID) {

    returnCode = sqlite3_open("../data/hospital.db", &db);

    std::string sql = "SELECT (ID ,NAME, PASSWORD) FROM PATIENT WHERE ID = ?;";
    sqlite3_stmt *stmt;
    int returnCode;

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    returnCode = sqlite3_bind_int(stmt, 1, patientID);
    returnCode = sqlite3_step(stmt);
    if (returnCode == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        std::string name =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        std::string password =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        sqlite3_finalize(stmt);
        return Patient(id, name, password);
    } else if (returnCode == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    } else {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return std::nullopt;
    };
}

optional<Patient>
HospitalDatabase::getPatientByNameAndPassword(string name, string password) {

    int returnCode = sqlite3_open("../data/hospital.db", &db);

    std::string sql = "SELECT ID, NAME, PASSWORD FROM PATIENT WHERE NAME = ? "
                      "AND PASSWORD = ?;";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    returnCode = sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    returnCode =
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    returnCode = sqlite3_step(stmt);

    if (returnCode == SQLITE_ROW) {
        int retrievedID = sqlite3_column_int(stmt, 0);

        std::string retrievedName =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));

        std::string retrievedPassword =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        sqlite3_finalize(stmt);
        return Patient(retrievedID, retrievedName, retrievedPassword);
    } else if (returnCode == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    } else {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return std::nullopt;
    }
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

void HospitalDatabase::updatePatient(unsigned short patientId, string attributeName, string attributeValue) {
    returnCode = sqlite3_open("../data/hospital.db", &db);
    if (!verifyErrorCode()) {
        return;
    }
    string sql = "UPDATE PATIENT SET " + attributeName + " = " + attributeValue + " WHERE ID = " + to_string(patientId) + ";";

    int returnCode = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (verifyErrorCode()) {
        cout << "Patient with ID = " << patientId << " updated" << endl;
    }
}

string HospitalDatabase::getPatientData(unsigned short patientId, string attributeName) {
    returnCode = sqlite3_open("../data/hospital.db", &db);
    if (!verifyErrorCode()) {
        return "";
    }
    string sql = "SELECT " + attributeName + " FROM PATIENT WHERE ID = " + to_string(patientId) + ";";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (!verifyErrorCode()) {
        return "";
    }

    returnCode = sqlite3_step(stmt);
    if (returnCode == SQLITE_ROW) {
        const unsigned char *data = sqlite3_column_text(stmt, 0);
        return reinterpret_cast<const char *>(data);
    } else {
        return "";
    }
}