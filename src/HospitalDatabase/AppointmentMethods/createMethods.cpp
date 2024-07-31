#include "../../../include/HospitalDatabase/HospitalDatabase.h"

void HospitalDatabase::createAppointment(Doctor doctor, Patient patient,
                                         Date date, string procedure) {
    returnCode = sqlite3_open("../data/hospital.db", &db);

    string sql = "INSERT INTO SCHEDULE (STATUS, PATIENT_ID, DOCTOR_ID, "
                 "PROCEDURE, SESSION) VALUES (?, ?, ?, ?, ?);";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (!verifyErrorCode()) {
        cout << "Preparation failed\n";
        sqlite3_close(db);
        return;
    }

    returnCode = sqlite3_bind_text(stmt, 1, "MARCADO", -1, SQLITE_STATIC);
    if (!verifyErrorCode()) {
        cout << "Preparation failed\n";
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    returnCode = sqlite3_bind_int(stmt, 2, patient.getUserID());
    if (!verifyErrorCode()) {
        cout << "Preparation failed\n";
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    returnCode = sqlite3_bind_int(stmt, 3, patient.getUserID());
    if (!verifyErrorCode()) {
        cout << "Preparation failed\n";
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    returnCode =
        sqlite3_bind_text(stmt, 4, procedure.c_str(), -1, SQLITE_STATIC);
    if (!verifyErrorCode()) {
        cout << "Preparation failed\n";
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    returnCode =
        sqlite3_bind_text(stmt, 5, date.toString().c_str(), -1, SQLITE_STATIC);
    if (!verifyErrorCode()) {
        cout << "Preparation failed\n";
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    returnCode = sqlite3_step(stmt);

    sqlite3_close(db);
}
