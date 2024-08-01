#include "../../../include/HospitalDatabase/HospitalDatabase.h"

void HospitalDatabase::deleteAppointment(int AppointmentId) {
    returnCode = sqlite3_open("../data/hospital.db", &db);
    if (!verifyErrorCode()) {
        return;
    }
    string sql =
        "DELETE FROM SCHEDULE WHERE ID = " + to_string(AppointmentId) + ";";

    int returnCode = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (verifyErrorCode()) {
        cout << "Appointment with ID = " << AppointmentId << " deleted" << endl;
    }

    sqlite3_close(db);
}
