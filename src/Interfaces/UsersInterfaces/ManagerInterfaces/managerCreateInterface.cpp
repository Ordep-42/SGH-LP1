
#include "../../../../include/Interface.h"
#include "../../../../include/Users/Manager.h"
#include <cstdio>
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
        HospitalInterface::managerInterface();
    }
    HospitalInterface::managerInterface();
}

void HospitalInterface::managerCreatePatient() {
    system("clear");
    titleMaker("CRIAR PACIENTE");

    Manager *manager = dynamic_cast<Manager *>(this->getCurrentUser());

    string patientName, patientPassword;
    cout << "Digite o nome do paciente: ";
    cin >> patientName;
    getchar();
    cout << "\nDigite a senha do paciente: ";
    cin >> patientPassword;
    cout << endl;

    Patient newPatient = Patient(patientName, patientPassword);

    manager->createPatient(newPatient);
}

void HospitalInterface::managerCreateAttendant() {
    system("clear");
    titleMaker("CRIAR ATENDENTE");

    Manager *manager = dynamic_cast<Manager *>(this->getCurrentUser());

    string attendantName, attendantPassword;
    cout << "Digite o nome do atendente: ";
    cin >> attendantName;
    getchar();
    cout << "\nDigite a senha do atendente: ";
    cin >> attendantPassword;
    cout << endl;

    User attendant = User(attendantName, attendantPassword, Roles::Assistant);

    manager->createAttendant(attendant);
}

void HospitalInterface::managerCreateDoctor() {
    system("clear");
    titleMaker("CRIAR DOUTOR");

    Manager *manager = dynamic_cast<Manager *>(this->getCurrentUser());

    string doctorName, doctorPassword, doctorSpecialty;
    int doctorConsultCost;
    cout << "Digite o nome do doutor: ";
    cin >> doctorName;
    getchar();
    cout << "Digite a senha do doutor: ";
    cin >> doctorPassword;
    getchar();
    cout << "Digite a especialidade do doutor: ";
    cin >> doctorSpecialty;
    getchar();
    cout << "Digite o preço da consulta do doutor: ";
    cin >> doctorConsultCost;
    getchar();
    cout << endl;

    Doctor doctor =
        Doctor(doctorName, doctorPassword, doctorSpecialty, doctorConsultCost);

    manager->createDoctor(doctor);
}

void HospitalInterface::managerCreateManager() {
    system("clear");
    titleMaker("CRIAR MANAGER");

    Manager *manager = dynamic_cast<Manager *>(this->getCurrentUser());

    string managerName, managerPassword;
    cout << "Digite o nome do gestor: ";
    cin >> managerName;
    getchar();
    cout << "\nDigite a senha do gestor: ";
    cin >> managerPassword;
    getchar();
    cout << endl;

    Manager newManager = Manager(managerName, managerPassword);

    manager->createManager(newManager);
}
