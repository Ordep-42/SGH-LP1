#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <unistd.h>

void HospitalDatabase::createDoctor(Doctor doctor) {
    int returnCode = sqlite3_open("../data/hospital.db", &db);

    std::string sql = "INSERT INTO DOCTOR (NAME, PASSWORD, CONSULT_COST, "
                      "SPECIALTY) VALUES (?, ?, ?, ?);";

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, doctor.getName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, doctor.getPassword().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, doctor.getConsultCost());
    sqlite3_bind_text(stmt, 4, doctor.getEspecialidade().c_str(), -1,
                      SQLITE_STATIC);

    sqlite3_step(stmt);

    sqlite3_close(db);
}

optional<Doctor> HospitalDatabase::getDoctorByID(int doctorID) {
    int returnCode = sqlite3_open("../data/hospital.db", &db);

    std::string sql = "SELECT ID ,NAME, PASSWORD, SPECIALTY, CONSULT_COST FROM "
                      "DOCTOR WHERE ID = ?;";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    returnCode = sqlite3_bind_int(stmt, 1, doctorID);

    returnCode = sqlite3_step(stmt);
    if (returnCode == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);

        string name =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));

        string password =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        string especialidade =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
        int consultCost = sqlite3_column_int(stmt, 4);

        sqlite3_finalize(stmt);
        return Doctor(id, name, password, especialidade, consultCost);
    } else if (returnCode == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    } else {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return std::nullopt;
    };
}

optional<Doctor> HospitalDatabase::getDoctorByNameAndPassword(string name,
                                                              string password) {

    int returnCode = sqlite3_open("../data/hospital.db", &db);

    std::string sql = "SELECT ID ,NAME, PASSWORD, SPECIALTY, CONSULT_COST FROM "
                      "DOCTOR WHERE NAME = ? AND PASSWORD = ?;";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    returnCode = sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    returnCode =
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    returnCode = sqlite3_step(stmt);

    if (returnCode == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);

        string name =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));

        string password =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        string especialidade =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
        int consultCost = sqlite3_column_int(stmt, 4);

        sqlite3_finalize(stmt);
        return Doctor(id, name, password, especialidade, consultCost);
    } else if (returnCode == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    } else {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return std::nullopt;
    };
}

set<int> HospitalDatabase::getAllDoctors() {
    set<int> idList;

    returnCode = sqlite3_open("../data/hospital.db", &db);
    if (!verifyErrorCode()) {
        return idList;
    }

    std::string sql = "SELECT * FROM DOCTOR;";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (!verifyErrorCode()) {
        return idList;
    }

    // Largura das colunas
    const int width_id = 10;
    const int width_nome = 20;
    const int width_password = 20;
    const int width_consultCost = 15;
    const int width_specialty = 20;

    // Cabeçalhos
    // cout << left << setw(width_id) << "id" << setw(width_nome) << "nome"
    //      << setw(width_consultCost) << "consultCost" 
    //      << setw(width_specialty) << "specialty" << endl;
    while ((returnCode = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *nome = sqlite3_column_text(stmt, 1);
        //const unsigned char *password = sqlite3_column_text(stmt, 2);
        int consultCost = sqlite3_column_int(stmt, 3);
        const unsigned char *specialty = sqlite3_column_text(stmt, 4);

        idList.insert(id);

        // cout << left << setw(width_id) << id << setw(width_nome) << nome
        //      << setw(width_consultCost) << consultCost 
        //      << setw(width_specialty) << specialty << endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return idList;
}

set<int> HospitalDatabase::listDoctors() {
    set<int> idList;

    returnCode = sqlite3_open("../data/hospital.db", &db);
    if (!verifyErrorCode()) {
        return idList;
    }

    std::string sql = "SELECT * FROM DOCTOR;";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (!verifyErrorCode()) {
        return idList;
    }

    // Largura das colunas
    const int width_id = 10;
    const int width_nome = 20;
    const int width_password = 20;
    const int width_consultCost = 15;
    const int width_specialty = 20;

    // Cabeçalhos
    cout << left << setw(width_id) << "id" << setw(width_nome) << "nome"
         << setw(width_consultCost) << "consultCost" 
         << setw(width_specialty) << "specialty" << endl;
    while ((returnCode = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *nome = sqlite3_column_text(stmt, 1);
        //const unsigned char *password = sqlite3_column_text(stmt, 2);
        int consultCost = sqlite3_column_int(stmt, 3);
        const unsigned char *specialty = sqlite3_column_text(stmt, 4);

        idList.insert(id);

        cout << left << setw(width_id) << id << setw(width_nome) << nome
             << setw(width_consultCost) << consultCost 
             << setw(width_specialty) << specialty << endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return idList;
}

void HospitalDatabase::deleteDoctor(unsigned short doctorId) {
    returnCode = sqlite3_open("../data/hospital.db", &db);
    if (!verifyErrorCode()) {
        return;
    }
    string sql = "DELETE FROM DOCTOR WHERE ID = " + to_string(doctorId) + ";";

    int returnCode = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (verifyErrorCode()) {
        cout << "Doctor with ID = " << doctorId << " deleted" << endl;
    }

    sqlite3_close(db);
}

bool HospitalDatabase::validateDoctor(string name, string password) {
    return true;
}
