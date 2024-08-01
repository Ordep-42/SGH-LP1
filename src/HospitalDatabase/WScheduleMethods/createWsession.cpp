#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <optional>
#include <string>
#include <unistd.h>

void HospitalDatabase::createWSession(int doctor_id, Session session) {
    returnCode = sqlite3_open("../data/hospital.db", &db);

    string sql = "INSERT INTO WORK_SCHEDULE (DOCTOR_ID "
                 ", SESSION) VALUES (?, ?);";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    returnCode = sqlite3_bind_int(stmt, 1, doctor_id);
    string sessionStr = session.toString();
    cout << sessionStr << endl;
    returnCode =
        sqlite3_bind_text(stmt, 2, sessionStr.c_str(), -1, SQLITE_STATIC);

    cout << "RC after prepare_v2: " << returnCode << endl;
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    sleep(3);
}
