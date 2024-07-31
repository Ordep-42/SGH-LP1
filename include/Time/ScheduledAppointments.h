
#ifndef SCHEDULEDAPPOINTMENTS_H
#define SCHEDULEDAPPOINTMENTS_H

#include "Appointment.h"
#include <optional>
#include <string>
#include <vector>

using namespace std;

class ScheduledAppointments {
  private:
    // int id;
    // int doctor_id; //??
    vector<Appointment> appointments;
    // se colocar doctor id, vai ter q fazer um vetor de scheduled appointments
    // pra acessar o de todos os medicos, mas ainda é bem viável.

  public:
    ScheduledAppointments(
        /*int id,*/ vector<Appointment> appointments /*, int doctor_id*/);
    ScheduledAppointments(/*int id, int doctor_id*/);
    // ScheduledAppointments() = default;

    // GETTERS:
    // int getID();
    // int getDoctorID();
    vector<Appointment> getAppointments();

    // SEARCH'S / FILTERS:
    // Lembre que é só misturar searchbyStatus("canceled").searchbyDateAter();
    // ou combine time e date pra filtrar por seção.

    // TIME:

    ScheduledAppointments searchByTime(Time thatTime);
    ScheduledAppointments searchByTimeAfter(Time thatTime);
    ScheduledAppointments searchByTimeBefore(Time thatTime);
    ScheduledAppointments searchByTimeBetween(Time time1, Time time2);

    // DATE:
    ScheduledAppointments searchByDate(Date thatDate);
    ScheduledAppointments searchByDateAfter(Date thatDate);
    ScheduledAppointments searchByDateBefore(Date thatDate);
    ScheduledAppointments searchByDateBetween(Date date1, Date date2);

    // APPOINTMENTS ATRBTS:
    ScheduledAppointments searchByPatient(int thatPatientID);
    ScheduledAppointments searchByAppointmentId(int thatAppointmentID);
    ScheduledAppointments searchByStatus(string thatStatus);
    ScheduledAppointments searchByProcedure(string thatProcedure);

    // string status; // Marcada, confirmada, cancelada Xou finalizada
    // const short room;
    // const int doctorID;

    // CHECKERS:
    bool testSessionPresence(Session testMe);
    bool testSessionAvaiability(Session testMe);
    bool isAppointed(Session test);

    // ANOTHER STUFF:
    void safeAdd(Appointment addMe);
    void safeAdd(vector<Appointment> addMe);

    optional<Appointment> nextAppointment();
    Appointment lastAppointment();
    ScheduledAppointments AppointmentsToHappen();

    vector<string> toString() {
        vector<string> returnMe;
        if (getAppointments().size() == 0) {
            return returnMe;
        }
        for (Appointment app : getAppointments()) {
            returnMe.push_back(app.toLINEARString());
        }
        return returnMe;
    }
    // Pra marcar uma consulta:
    // Session nextAvaiableSection();

    // make appointment
};

// Funções auxiliares
#endif // !APPOINTMENT_H
