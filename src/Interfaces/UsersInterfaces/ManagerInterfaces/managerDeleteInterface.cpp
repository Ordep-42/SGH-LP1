#include "../../../../include/HospitalDatabase/HospitalDatabase.h"

#include "../../../../include/Interface.h"
#include "../../../../include/Users/Manager.h"
#include <cstdio>
#include <cstdlib>

void HospitalInterface::managerDeleteInterface() {
    system("clear");
    titleMaker("DELETAR USUÁRIO");

    vector<string> choices;
    choices.push_back("Paciente");
    choices.push_back("Atendente");
    choices.push_back("Doutor");
    choices.push_back("Gestor");
    choices.push_back("Voltar");
    int choice = choiceMaker(choices);

    switch (choice) {
    case 1:
        HospitalInterface::managerDeletePatient();
        break;
    case 2:
        HospitalInterface::managerDeleteAttendant();
        break;
    case 3:
        HospitalInterface::managerDeleteDoctor();
        break;
    case 4:
        HospitalInterface::managerDeleteManager();
        break;
    case 5:
        HospitalInterface::managerInterface();
    }
    HospitalInterface::managerInterface();
}

void HospitalInterface::managerDeletePatient() {
    system("clear");
    titleMaker("DELETAR PACIENTE");
    HospitalDatabase::listPatients();
    hr();

    Manager *manager = dynamic_cast<Manager *>(this->getCurrentUser());
    int patientID;

    cout << "Digite o ID do usuário que você quer deletar: ";
    cin >> patientID;
    getchar();
    manager->deletePatient(patientID);
}

void HospitalInterface::managerDeleteAttendant() {
    system("clear");
    titleMaker("DELETAR ATENDENTE");
    HospitalDatabase::listAttendants();
    hr();

    Manager *manager = dynamic_cast<Manager *>(this->getCurrentUser());
    int attendantID;

    cout << "Digite o ID do usuário que você quer deletar: ";
    cin >> attendantID;
    getchar();
    manager->deleteAttendant(attendantID);
}

void HospitalInterface::managerDeleteDoctor() {
    system("clear");
    titleMaker("DELETAR DOUTOR");
    HospitalDatabase::listDoctors();
    hr();

    Manager *manager = dynamic_cast<Manager *>(this->getCurrentUser());
    int doctorID;

    cout << "Digite o ID do usuário que você quer deletar: ";
    cin >> doctorID;
    getchar();
    manager->deleteDoctor(doctorID);
}

void HospitalInterface::managerDeleteManager() {
    system("clear");
    titleMaker("DELETAR DOUTOR");
    HospitalDatabase::listManagers();
    hr();

    Manager *manager = dynamic_cast<Manager *>(this->getCurrentUser());
    int managerID;

    cout << "Digite o ID do usuário que você quer deletar: ";
    cin >> managerID;
    getchar();
    manager->deleteManager(managerID);
}
