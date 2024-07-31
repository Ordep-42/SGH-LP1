#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <iomanip>

// void HospitalDatabase::listAppointmentsByPatient(int patientId) {
//     const char *sql = "SELECT ID, STATUS, PATIENT_ID, DOCTOR_ID, PROCEDURE, "
//                       "SESSION"
//                       "FROM SCHEDULE WHERE PATIENT_ID = ?;";

//     sqlite3_stmt *stmt;
//     if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
//         cerr << "Failed to fetch data: " << sqlite3_errmsg(db) << endl;
//         return;
//     }

//     sqlite3_bind_int(stmt, 1, patientId);

//     vector<Appointment> appointments;

//     while (sqlite3_step(stmt) == SQLITE_ROW) {
//         int id = sqlite3_column_int(stmt, 0);
//         string status =
//             reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
//         int patientID = sqlite3_column_int(stmt, 2);
//         int doctorID = sqlite3_column_int(stmt, 3);
//         string procedure =
//             reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
//         string session =
//             reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5));

//         Appointment app = Appointment(id, stringToSession(session), status,
//                                       patientID, doctorID, procedure);

//         appointments.push_back(app);
//     }

//     sqlite3_finalize(stmt);

//     if (appointments.empty()) {
//         cout << "No appointments found for patient ID " << patientId << "."
//              << endl;
//     } else {
//         // Largura das colunas
//         const int width_id = 10;
//         const int width_nome = 20;
//         const int width_password = 20;
//         const int width_consultCost = 15;
//         const int width_specialty = 20;

//         cout << left << setw(width_id) << "id" << setw(width_nome) <<
//         "status"
//              << setw(width_password) << "password" << setw(width_consultCost)
//              << "consultCost" << setw(width_specialty) << "specialty" <<
//              endl;
//         cout << "Appointments for patient ID " << patientId << ":" << endl;
//         for (auto &app : appointments) {
//             cout << left << setw(width_id) << app.getId() << setw(width_nome)
//                  << app.getStatus() << setw(width_password)
//                  << app.getSession().toString() << setw(width_consultCost)
//                  << app.getDoctorID() << setw(width_specialty)
//                  << app.getProcedure() << endl;
//         }
//     }
// }

vector<Appointment>
HospitalDatabase::getAppointmentsByPatientID(int patientId) {
    const char *sql = "SELECT ID, STATUS, PATIENT_ID, DOCTOR_ID, PROCEDURE, "
                      "SESSION"
                      "FROM SCHEDULE WHERE PATIENT_ID = ?;";

    vector<Appointment> appointments;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, patientId);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        string status =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        int patientID = sqlite3_column_int(stmt, 2);
        int doctorID = sqlite3_column_int(stmt, 3);
        string procedure =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
        string session =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5));

        Appointment app = Appointment(id, stringToSession(session), status,
                                      patientID, doctorID, procedure);

        appointments.push_back(app);
    }

    sqlite3_finalize(stmt);
    return appointments;
}

vector<Appointment> HospitalDatabase::getAppointmentsByDoctorID(int doctorID) {
    const char *sql = "SELECT ID, STATUS, PATIENT_ID, DOCTOR_ID, PROCEDURE, "
                      "SESSION"
                      "FROM SCHEDULE WHERE DOCTOR_ID = ?;";

    vector<Appointment> appointments;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, doctorID);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        string status =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        int patientID = sqlite3_column_int(stmt, 2);
        int doctorID = sqlite3_column_int(stmt, 3);
        string procedure =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
        string session =
            reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5));

        Appointment app = Appointment(id, stringToSession(session), status,
                                      patientID, doctorID, procedure);

        appointments.push_back(app);
    }

    sqlite3_finalize(stmt);
    return appointments;
};
