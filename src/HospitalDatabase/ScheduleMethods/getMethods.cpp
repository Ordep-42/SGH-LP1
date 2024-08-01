#include "../../../include/HospitalDatabase/HospitalDatabase.h"

Schedule HospitalDatabase::getScheduleByDoctorID(int doctorID) {
    vector<WorkSession> wss = getWorkSessionsByDoctorID(doctorID);
    cout << "foi " << endl;
    cout << "foi " << endl;
    // for(WorkSession wSession : wss){
    //     cout << "foi " << endl;
    // }
    vector<Appointment> apps = getAppointmentsByDoctorID(doctorID);

    WorkSchedule workSchedule = WorkSchedule(wss);
    ScheduledAppointments appointments = ScheduledAppointments(apps);

    Schedule newSchedule(appointments, workSchedule);
    return newSchedule;
}
