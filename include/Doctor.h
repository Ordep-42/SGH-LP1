#ifndef DOCTOR_H
#define DOCTOR_H

#include "Schedule.h"
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

  public:
    Doctor(string name, string password, string especialidade);

    vector<Section> getWorkSchedule();
    vector<User> getScheduledPatients();
    vector<User> getScheduledPatientsByDate();

    void doAppointment(Section);
    void requestMedicalEquipment(Equipment);

    string getEspecialidade();
    void setEspecialidade();
};

#endif // !DOCTOR_H
