#include "../include/Doctor.h"
#include "../include/HospitalDatabase.h"
#include <string>

Doctor::Doctor(string name, string password, string especialidade)
    : User(name, password, Medic), especialidade(especialidade) {
    this->especialidade = especialidade;
}

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
