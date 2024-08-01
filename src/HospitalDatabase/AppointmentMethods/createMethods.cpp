#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <unistd.h>

void HospitalDatabase::createAppointment(Appointment newAppointment) {
    int doctorID = newAppointment.getDoctorID();
    int patientID = newAppointment.getPatientID();
    Date date = newAppointment.getSession().getDate();
    string procedure = newAppointment.getProcedure();

    returnCode = sqlite3_open("../data/hospital.db", &db);

    string sql = "INSERT INTO SCHEDULE (STATUS, PATIENT_ID, DOCTOR_ID, "
                 "PROCEDURE, SESSION) VALUES (?, ?, ?, ?, ?);";

    returnCode = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    cout << returnCode << endl;
    returnCode = sqlite3_bind_text(stmt, 1, "MARCADO", -1, SQLITE_STATIC);

    returnCode = sqlite3_bind_int(stmt, 2, doctorID);

    returnCode = sqlite3_bind_int(stmt, 3, patientID);

    returnCode =
        sqlite3_bind_text(stmt, 4, procedure.c_str(), -1, SQLITE_STATIC);

    returnCode =
        sqlite3_bind_text(stmt, 5, date.toString().c_str(), -1, SQLITE_STATIC);

    cout << returnCode << endl;
    returnCode = sqlite3_step(stmt);

    cout << returnCode << endl;
    sleep(5);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
