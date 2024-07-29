#include "../../../include/Users/Doctor.h"
#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <string>

Doctor::Doctor(string name, string password, string especialidade)
    : User(name, password, Roles::Doctor), especialidade(especialidade) {
    this->especialidade = especialidade;
}

Doctor::Doctor(string name, string password, string especialidade,
               int consultCost)
    : User(name, password, Roles::Doctor), especialidade(especialidade),
      consultCost(consultCost) {}

vector<Appointment> Doctor::getAppointments() {
    vector<string> stringedAppointments =
        HospitalDatabase::getAppointmentsByDoctor(this->getUserID());
    vector<Appointment> x;

    return x;
}

string Doctor::getEspecialidade() { return especialidade; }
void Doctor::setEspecialidade(string especialidade) {
    this->especialidade = especialidade;
}

int Doctor::getConsultCost() { return this->consultCost; }
