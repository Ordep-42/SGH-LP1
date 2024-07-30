#include "../../../include/HospitalDatabase/HospitalDatabase.h"

void HospitalDatabase::createWSession(Doctor doctor, Session session) {
    returnCode = sqlite3_open("../data/hospital.db", &db);

    string sql = "INSERT INTO WORK_SCHEDULE (DOCTOR_ID, "
                 ", SESSION) VALUES (?, ?);";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (!verifyErrorCode()) {
        cout << "Preparation failed\n";
        sqlite3_close(db);
        return;
    }

    returnCode = sqlite3_bind_int(stmt, 1, doctor.getUserID());
    if (!verifyErrorCode()) {
        cout << "Preparation failed\n";
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    returnCode = sqlite3_bind_text(stmt, 2, session.toString().c_str(), -1,
                                   SQLITE_STATIC);
    if (!verifyErrorCode()) {
        cout << "Preparation failed\n";
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    returnCode = sqlite3_step(stmt);

    sqlite3_close(db);
}
