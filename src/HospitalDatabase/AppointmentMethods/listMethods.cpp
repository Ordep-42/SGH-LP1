#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <unistd.h>

vector<Appointment>
HospitalDatabase::getAppointmentsByPatientID(int patientId) {
    returnCode = sqlite3_open("../data/hospital.db", &db);
    const char *sql = "SELECT ID, STATUS, PATIENT_ID, DOCTOR_ID, PROCEDURE, "
                      "SESSION"
                      "FROM SCHEDULE WHERE PATIENT_ID = ?;";

    vector<Appointment> appointments;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt, 1, patientId);
    cout << "Cheguei aqui! " << endl;
    sleep(3);
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
    sqlite3_close(db);
    return appointments;
}

vector<Appointment> HospitalDatabase::getAppointmentsByDoctorID(int doctorID) {

    returnCode = sqlite3_open("../data/hospital.db", &db);
    const char *sql = "SELECT ID, STATUS, PATIENT_ID, DOCTOR_ID, PROCEDURE, "
                      "SESSION "
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
        cout << app.getId() << endl;
        appointments.push_back(app);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return appointments;
};
