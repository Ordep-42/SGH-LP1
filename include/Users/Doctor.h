#ifndef DOCTOR_H
#define DOCTOR_H

#include "../Time/Appointment.h"
#include "../Time/Schedule.h"
#include "../Time/Session.h"
#include "User.h"

using namespace std;

struct Equipment {
    int id;
    string name;
    string descrição;
    double preço;
};

class Doctor : public User {
  private:
    string especialidade;
    int consultCost;

  public:
    Doctor(string name, string password, string especialidade);

    vector<Session> getWorkSchedule();
    vector<Appointment> getAppointments();
    vector<User> getAppointmentsByDate();

    void doAppointment(Session);
    void requestMedicalEquipment(Equipment);

    int getConsultCost();
    void setConsultCost(int);

    string getEspecialidade();
    void setEspecialidade(string);
};

#endif // !DOCTOR_H
