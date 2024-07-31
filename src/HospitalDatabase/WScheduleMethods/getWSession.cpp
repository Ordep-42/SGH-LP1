#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <optional>

optional<WorkSession> HospitalDatabase::getWSessionByID(int WSessionID) {
    std::string sql =
        "SELECT (ID ,DOCTOR_ID, SESSION) FROM WORK_SCHEDULE WHERE ID = ?;";
    sqlite3_stmt *stmt;
    int returnCode;

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    returnCode = sqlite3_bind_int(stmt, 1, WSessionID);
    returnCode = sqlite3_step(stmt);

    if (returnCode == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        int doctorID = (sqlite3_column_int(stmt, 1));
        std::string stringSession =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        sqlite3_finalize(stmt);
        Session thisSession = stringToSession(stringSession);

        return WorkSession(thisSession.getTime(), thisSession.getDate(), id,
                           doctorID);
    } else if (returnCode == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    } else {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return std::nullopt;
    };
}

vector<WorkSession> HospitalDatabase::getWorkSessionsByDoctorID(int doctorID) {

    vector<WorkSession> wSchedule;

    std::string sql = "SELECT (ID ,DOCTOR_ID, SESSION) FROM WORK_SCHEDULE "
                      "WHERE DOCTOR_ID = ?;";
    sqlite3_stmt *stmt;
    int returnCode;

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    returnCode = sqlite3_bind_int(stmt, 1, doctorID);
    returnCode = sqlite3_step(stmt);

    while (returnCode == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        int doctorID = (sqlite3_column_int(stmt, 1));
        std::string stringSession =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        sqlite3_finalize(stmt);
        Session thisSession = stringToSession(stringSession);
        WorkSession ws = WorkSession(thisSession.getTime(),
                                     thisSession.getDate(), id, doctorID);
        wSchedule.push_back(ws);
    }
    sqlite3_finalize(stmt);

    return wSchedule;
}
