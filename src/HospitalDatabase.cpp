#include "../include/HospitalDatabase.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

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
                            "ID INTEGER PRIMARY KEY NOT NULL,"
                            "NAME TEXT NOT NULL,"
                            "PASSWORD TEXT NOT NULL);";

    const char *atendenteSql = "CREATE TABLE IF NOT EXISTS ATTENDANT("
                               "ID INTEGER PRIMARY KEY NOT NULL,"
                               "NAME TEXT NOT NULL,"
                               "PASSWORD TEXT NOT NULL);";

    const char *pacienteSql = "CREATE TABLE IF NOT EXISTS PATIENT("
                              "ID INTEGER PRIMARY KEY NOT NULL,"
                              "NAME TEXT NOT NULL,"
                              "PASSWORD TEXT NOT NULL);";

    const char *doutorSql = "CREATE TABLE IF NOT EXISTS DOCTOR("
                            "ID INTEGER PRIMARY KEY NOT NULL,"
                            "NAME TEXT NOT NULL,"
                            "PASSWORD TEXT NOT NULL,"
                            "CONSULT_COST INTEGER NOT NULL,"
                            "SPECIALTY TEXT NOT NULL";

    const char *agendaSql = "CREATE TABLE IF NOT EXISTS SCHEDULE("
                            "ID INTEGER PRIMARY KEY NOT NULL,"
                            "DATA TEXT NOT NULL,"
                            "CONSULTA TEXT NOT NULL);";

    const char *agenda_doutorSql =
        "CREATE TABLE IF NOT EXISTS SCHEDULE_DOCTOR("
        "DOCTOR_ID INTEGER,"
        "SCHEDULE_ID INTEGER,"
        "FOREIGN KEY (DOCTOR_ID) REFERENCES DOCTOR (ID),"
        "FOREIGN KEY (SCHEDULE_ID) REFERENCES SCHEDULE (ID),"
        "PRIMARY KEY (DOCTOR_ID, SCHEDULE_ID));";

    const char *agenda_pacienteSql =
        "CREATE TABLE IF NOT EXISTS SCHEDULE_PATIENT("
        "PATIENT_ID INTEGER,"
        "SCHEDULE_ID INTEGER,"
        "FOREIGN KEY (PATIENT_ID) REFERENCES PATIENT (ID),"
        "FOREIGN KEY (SCHEDULE_ID) REFERENCES SCHEDULE (ID),"
        "PRIMARY KEY (PATIENT_ID, SCHEDULE_ID));";

    returnCode = sqlite3_exec(db, gestorSql, 0, 0, &errMsg);
    returnCode = sqlite3_exec(db, atendenteSql, 0, 0, &errMsg);
    returnCode = sqlite3_exec(db, doutorSql, 0, 0, &errMsg);
    returnCode = sqlite3_exec(db, pacienteSql, 0, 0, &errMsg);
    returnCode = sqlite3_exec(db, agendaSql, 0, 0, &errMsg);
    returnCode = sqlite3_exec(db, agenda_doutorSql, 0, 0, &errMsg);
    returnCode = sqlite3_exec(db, agenda_pacienteSql, 0, 0, &errMsg);

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

void HospitalDatabase::setDBPointer(sqlite3 *db) { this->db = db; }
void HospitalDatabase::setErrMsg(char *errMsg) { this->errMsg = errMsg; }
void HospitalDatabase::setReturnCode(int returnCode) {
    this->returnCode = returnCode;
}

string HospitalDatabase::getFromAgenda(const char *sql) {
    string agenda = "";
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

string HospitalDatabase::getAgenda() {
    return getFromAgenda("SELECT (ID, DATA, CONSULTA) FROM SCHEDULE;");
}

string HospitalDatabase::getAgendaByPatient(User user) {
    ostringstream oss;

    // Isso só vai funcionar quando a Class Patient estiver ok! pra pegar o Id.
    oss << "SELECT (ID, DATA, CONSULTA) " << "FROM SCHEDULE "
        << "JOIN SCHEDULE_PATIENT ON PATIENT.ID = SCHEDULE_PATIENT.PATIENT_ID "
        << "WHERE SCHEDULE_PATIENT.PATIENT_ID =" /*<< user.getId() */
        << ";";

    string queryStr = oss.str();
    const char *sql = queryStr.c_str();

    return getFromAgenda(sql);
}

string HospitalDatabase::getAgendaByDate(Date date) {
    ostringstream oss;

    oss << "SELECT (ID, DATA, CONSULTA) " << "FROM SCHEDULE "
        << "WHERE SCHEDULE.DATA = " << date.getYear() << "/" << date.getMonth()
        << "/" << date.getDay();

    string queryStr = oss.str();
    const char *sql = queryStr.c_str();
    return getFromAgenda(sql);
}

string HospitalDatabase::getAgendaByDoctor(User user) {
    ostringstream oss;

    // Isso só vai funcionar quando a Class Doctor estiver ok! pra pegar o Id.
    oss << "SELECT (ID, DATA, CONSULTA) " << "FROM SCHEDULE "
        << "JOIN SCHEDULE_PATIENT ON PATIENT.ID = SCHEDULE_PATIENT.PATIENT_ID "
        << "WHERE SCHEDULE_PATIENT.PATIENT_ID =" /*<< user.getId() */
        << ";";

    string queryStr = oss.str();
    const char *sql = queryStr.c_str();

    return getFromAgenda(sql);
}
