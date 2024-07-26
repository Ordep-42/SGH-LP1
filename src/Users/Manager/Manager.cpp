#include "../../../include/Users/Manager.h"
#include "../../../include/HospitalDatabase/HospitalDatabase.h"

Manager::Manager(string name, string password)
    : User(name, password, Roles::Manager) {}

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

void Manager::deleteManager(Manager manager) {
    HospitalDatabase::deleteManager(manager.getUserID());
};

void Manager::deleteDoctor(Doctor doctor) {
    HospitalDatabase::deleteDoctor(doctor.getUserID());
}

void Manager::deletePatient(User patient) {
    HospitalDatabase::deletePatient(patient.getUserID());
}

void Manager::deleteAttendant(User attendant) {
    HospitalDatabase::deleteAttendant(attendant.getUserID());
}
