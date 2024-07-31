#include "../../../include/HospitalDatabase/HospitalDatabase.h"

Schedule HospitalDatabase::getScheduleByDoctorID(int doctorID) {
    vector<WorkSession> wss = getWorkSessionsByDoctorID(doctorID);
    vector<Appointment> apps = getAppointmentsByDoctorID(doctorID);

    WorkSchedule workSchedule = WorkSchedule(wss);
    ScheduledAppointments appointments = ScheduledAppointments(apps);

    Schedule newSchedule(appointments, workSchedule);
    return newSchedule;
}
