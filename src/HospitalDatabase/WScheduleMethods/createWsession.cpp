#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <optional>

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

optional<WorkSession> HospitalDatabase::getWSessionByID(int WSessionID) {

    std::string sql =
        "SELECT (ID ,DOCTOR_ID, SESSION) FROM WORK_SCHEDULE WHERE ID = ?;";
    sqlite3_stmt *stmt;
    int returnCode;

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (returnCode != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db)
                  << std::endl;
        return std::nullopt;
    }

    returnCode = sqlite3_bind_int(stmt, 1, WSessionID);
    if (returnCode != SQLITE_OK) {
        std::cerr << "Failed to bind WSession ID: " << sqlite3_errmsg(db)
                  << std::endl;
        sqlite3_finalize(stmt);
        return std::nullopt;
    }

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
