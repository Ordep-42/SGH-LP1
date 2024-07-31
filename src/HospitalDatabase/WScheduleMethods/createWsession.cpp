#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <optional>

void HospitalDatabase::createWSession(Doctor doctor, Session session) {
    returnCode = sqlite3_open("../data/hospital.db", &db);

    string sql = "INSERT INTO WORK_SCHEDULE (DOCTOR_ID, "
                 ", SESSION) VALUES (?, ?);";

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, doctor.getUserID());
    sqlite3_bind_text(stmt, 2, session.toString().c_str(), -1, SQLITE_STATIC);

    sqlite3_step(stmt);

    sqlite3_close(db);
}
