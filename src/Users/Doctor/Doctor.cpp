#include "../../../include/Users/Doctor.h"
#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include <string>

Doctor::Doctor(string name, string password, string especialidade)
    : User(name, password, Roles::Doctor), especialidade(especialidade) {
    this->especialidade = especialidade;
}

Doctor::Doctor(int id, string name, string password, string especialidade,
               int consultCost) {
    this->userID = id;
    this->name = name;
    this->password = password;
    this->especialidade = especialidade;
    this->consultCost = consultCost;
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
