#include "../../../../include/HospitalDatabase/HospitalDatabase.h"
#include "../../../../include/Interface.h"
#include <cstdio>
#include <cstdlib>

void HospitalInterface::managerListInterface() {
    system("clear");
    titleMaker("LISTAR USUÁRIO");

    vector<string> choices;
    choices.push_back("Paciente");
    choices.push_back("Atendente");
    choices.push_back("Doutor");
    choices.push_back("Gestor");
    choices.push_back("Voltar");
    int choice = choiceMaker(choices);

    switch (choice) {
    case 1:
        HospitalInterface::managerListPatient();
        break;
    case 2:
        HospitalInterface::managerListAttendant();
        break;
    case 3:
        HospitalInterface::managerListDoctor();
        break;
    case 4:
        HospitalInterface::managerListManager();
        break;
    case 5:
        HospitalInterface::managerInterface();
    }
    HospitalInterface::managerInterface();
};

void HospitalInterface::managerListPatient() {
    system("clear");
    titleMaker("LISTAR PACIENTES");
    HospitalDatabase::listPatients();
    hr();
    cout << "Enter para continuar...";
    cin.get();
}

void HospitalInterface::managerListAttendant() {
    system("clear");
    titleMaker("LISTAR ATENDENTES");
    HospitalDatabase::listAttendants();
    hr();
    cout << "Enter para continuar...";
    cin.get();
}

void HospitalInterface::managerListDoctor() {
    system("clear");
    titleMaker("LISTAR DOUTORES");
    HospitalDatabase::listDoctors();
    hr();
    cout << "Enter para continuar...";
    cin.get();
}

void HospitalInterface::managerListManager() {
    system("clear");
    titleMaker("LISTAR GESTORES");
    HospitalDatabase::listManagers();
    hr();
    cout << "Enter para continuar...";
    cin.get();
}
