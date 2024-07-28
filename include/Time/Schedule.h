#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "ScheduledAppointments.h"
#include "WorkSchedule.h"
#include <string>
#include <vector>

using namespace std;

class Schedule {
  private:
    ScheduledAppointments scheduledAppointments;
    WorkSchedule workSchedule;

  public:
    // Constructor's:
    Schedule(/*int newDoctorID*/);
    Schedule(ScheduledAppointments newScheduledAppointments);
    Schedule(WorkSchedule newWorkSchedule);
    Schedule(ScheduledAppointments newScheduledAppointments,
             WorkSchedule newWorkSchedule);

    // Getter's:
    ScheduledAppointments getScheduledAppointments();
    WorkSchedule getWorkSchedule();
    // Poderia ter um doctorID, mas sobraria ainda mais

    WorkSchedule avaiableSessions();
    bool checkAvaiability(Session checkMe); // tryDate to the CatchTime ;)
    void makeAppointment(Appointment addMe);
    Session nextAvaiableSession();
};

// Funções auxiliares

#endif // !SCHEDULE_H
