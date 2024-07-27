#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "../Users/User.h"
#include "Appointment.h"
#include "Session.h"
#include "Time.h"
#include <string>
#include <vector>

using namespace std;

class Schedule {
  private:
    vector<Appointment> scheduledAppointments;
    vector<Session> getWorkSchld();

    // void setWorkSchld(vector<Section> newWorkSchld);

    Schedule() = default;

    // bool checkAvailability(Date tryDate, Time tryTime); // tryDate to the
    // CatchTime ;)
};

// Funções auxiliares

#endif // !SCHEDULE_H
