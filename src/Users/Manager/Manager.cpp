#include "../../../include/Users/Manager.h"
#include "../../../include/HospitalDatabase/HospitalDatabase.h"

Manager::Manager(string name, string password)
    : User(name, password, Roles::Manager) {}

Manager::Manager(int id, string name, string password)
    : User(name, password, Roles::Manager) {
    this->userID = id;
}

void Manager::createManager(Manager manager) {
    HospitalDatabase::createManager(manager);
}

void Manager::createDoctor(Doctor doctor) {
    HospitalDatabase::createDoctor(doctor);
}

void Manager::createPatient(User patient) {
    HospitalDatabase::createPatient(patient);
}

void Manager::createAttendant(User attendant) {
    HospitalDatabase::createAttendant(attendant);
}

void Manager::deleteManager(int managerId) {
    HospitalDatabase::deleteManager(managerId);
};

void Manager::deleteDoctor(int doctorId) {
    HospitalDatabase::deleteDoctor(doctorId);
}

void Manager::deletePatient(int patientId) {
    HospitalDatabase::deletePatient(patientId);
}

void Manager::deleteAttendant(int attendantId) {
    HospitalDatabase::deleteAttendant(attendantId);
}
