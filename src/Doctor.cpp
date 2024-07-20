#include "../include/Doctor.h"
#include <string>

Doctor::Doctor(string name, string password, string especialidade)
    : User(name, password, Medic), especialidade(especialidade) {
    this->especialidade = especialidade;
}

string Doctor::getEspecialidade() { return especialidade; }
