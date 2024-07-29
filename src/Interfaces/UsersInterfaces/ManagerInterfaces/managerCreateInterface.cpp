
#include "../../../../include/Interface.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

void HospitalInterface::managerCreateInterface() {
    system("clear");
    titleMaker("CRIAR NOVO USUÁRIO");

    vector<string> choices;
    choices.push_back("Paciente");
    choices.push_back("Atendente");
    choices.push_back("Doutor");
    choices.push_back("Gestor");
    choices.push_back("Voltar");
    int choice = choiceMaker(choices);

    switch (choice) {
    case 1:
        HospitalInterface::managerCreatePatient();
        break;
    case 2:
        HospitalInterface::managerCreateAttendant();
        break;
    case 3:
        HospitalInterface::managerCreateDoctor();
        break;
    case 4:
        HospitalInterface::managerCreateManager();
        break;
    case 5:
        return;
    }
}

void HospitalInterface::managerCreatePatient() {
    system("clear");
    titleMaker("CRIAR PACIENTE");

    cout << "Digite o nome do paciente: "
}
