#include "../../include/HospitalDatabase/HospitalDatabase.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

sqlite3 *HospitalDatabase::db;
sqlite3_stmt *HospitalDatabase::stmt;
char *HospitalDatabase::errMsg;
int HospitalDatabase::returnCode;

HospitalDatabase::HospitalDatabase() {
    sqlite3 *db;
    char *errMsg;
    int returnCode = sqlite3_open("../data/hospital.db", &db);

    if (returnCode) {
        std::cerr << "Não foi possível abrir banco de dados: "
                  << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Acesso ao banco de dados realizado" << std::endl;
    }

    const char *gestorSql = "CREATE TABLE IF NOT EXISTS MANAGER("
                            "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "NAME TEXT NOT NULL,"
                            "PASSWORD TEXT NOT NULL);";

    const char *atendenteSql = "CREATE TABLE IF NOT EXISTS ATTENDANT("
                               "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                               "NAME TEXT NOT NULL,"
                               "PASSWORD TEXT NOT NULL);";

    const char *pacienteSql = "CREATE TABLE IF NOT EXISTS PATIENT("
                              "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "NAME TEXT NOT NULL,"
                              "PASSWORD TEXT NOT NULL);";

    const char *doutorSql = "CREATE TABLE IF NOT EXISTS DOCTOR("
                            "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "NAME TEXT NOT NULL,"
                            "PASSWORD TEXT NOT NULL,"
                            "CONSULT_COST INTEGER NOT NULL,"
                            "SPECIALTY TEXT NOT NULL);";

    const char *agendaSql = "CREATE TABLE IF NOT EXISTS SCHEDULE("
                            "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "DATA TEXT NOT NULL,"
                            "STATUS TEXT NOT NULL,"
                            "PATIENT_ID INTEGER NOT NULL,"
                            "DOCTOR_ID INTEGER NOT NULL,"
                            "FOREIGN KEY (PATIENT_ID) REFERENCES PATIENT (ID)"
                            "FOREIGN KEY (DOCTOR_ID) REFERENCES DOCTOR (ID));";

    returnCode = sqlite3_exec(db, gestorSql, 0, 0, &errMsg);
    returnCode = sqlite3_exec(db, atendenteSql, 0, 0, &errMsg);
    returnCode = sqlite3_exec(db, doutorSql, 0, 0, &errMsg);
    returnCode = sqlite3_exec(db, pacienteSql, 0, 0, &errMsg);
    returnCode = sqlite3_exec(db, agendaSql, 0, 0, &errMsg);

    if (returnCode != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        return;
    }
    std::cout << "Database Tables created successfully" << std::endl;

    this->returnCode = returnCode;
    this->errMsg = errMsg;
    this->db = db;

    sqlite3_close(db);
}

sqlite3 *HospitalDatabase::getDBPointer() { return this->db; }
char *HospitalDatabase::getErrMsg() { return this->errMsg; }
int HospitalDatabase::getReturnCode() { return this->returnCode; }

string HospitalDatabase::getFromSchedule(const char *sql) {
    string agenda = "";
    returnCode = sqlite3_open("../data/hospital.db", &db);

    if (returnCode) {
        std::cerr << "Não foi possível abrir banco de dados: "
                  << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Acesso ao banco de dados realizado" << std::endl;
    }

    returnCode = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (!verifyErrorCode()) {
        exit(1);
    };

    while ((returnCode = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *data = sqlite3_column_text(stmt, 1);
        const unsigned char *consulta = sqlite3_column_text(stmt, 2);

        ostringstream oss;
        oss << id << ", " << data << ", " << consulta << "\n";
        string result = oss.str();
        agenda.append(result);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return agenda;
}

string HospitalDatabase::getScheduleByDate(Date date) {
    ostringstream oss;

    oss << "SELECT * " << "FROM SCHEDULE "
        << "WHERE SCHEDULE.DATA = " << date.getYear() << "/" << date.getMonth()
        << "/" << date.getDay();

    string queryStr = oss.str();
    const char *sql = queryStr.c_str();
    return getFromSchedule(sql);
}

vector<string>
HospitalDatabase::getAppointmentsByDoctor(short unsigned doctorId) {
    ostringstream oss;

    oss << "SELECT (ID, DATA, STATUS, PATIENT_ID) " << "FROM SCHEDULE "
        << "WHERE SCHEDULE_PATIENT.DOCTOR_ID =" << doctorId << ";";

    string queryStr = oss.str();
    const char *sql = queryStr.c_str();
    vector<string> agenda;
    returnCode = sqlite3_open("../data/hospital.db", &db);

    if (returnCode) {
        std::cerr << "Não foi possível abrir banco de dados: "
                  << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Acesso ao banco de dados realizado" << std::endl;
    }
    returnCode = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (returnCode != SQLITE_OK) {
        std::cerr << "Statement com erro: " << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }

    while ((returnCode = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *data = sqlite3_column_text(stmt, 1);
        const unsigned char *status = sqlite3_column_text(stmt, 2);
        int patient_id = sqlite3_column_int(stmt, 3);

        ostringstream oss;
        oss << id << ", " << data << ", " << status << "\n";
        string result = oss.str();
        agenda.push_back(result);
    }
    return agenda;
}

bool HospitalDatabase::verifyErrorCode() {
    if (returnCode != SQLITE_OK) {
        std::cerr << "SQLITE ERROR : " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
};
