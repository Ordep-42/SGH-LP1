#include "../../../include/Users/Patient.h"

using namespace std;

Patient::Patient(unsigned short newUserID, string newLogin, string newPassWord,
                 string newName, Date newBirthDate, string newCpf,
                 Gender newGender, CivilStatus newCivilStatus,
                 string newAddress, string newPhoneNumber, string newEmail,
                 vector<EmergencyContact> newEmergencyContacts,
                 MedicalFile newMedicalFile)
    : User(newUserID, newLogin, newPassWord, newName, newCpf, newBirthDate, newGender,
           newCivilStatus, newAddress, newPhoneNumber, newEmail),
      emergencyContacts(newEmergencyContacts), medicalFile(newMedicalFile) {}

// Getters
vector<EmergencyContact> Patient::getEmergencyContacts() {
    return emergencyContacts;
}

MedicalFile Patient::getMedicalFile() { return medicalFile; }

vector<Appointment> Patient::getScheduledAppointments() {
    return scheduledAppointments;
}

vector<Appointment> Patient::getEndedAppointments() {
    return endedAppointments;
}

vector<Appointment> Patient::getCanceledAppointments() {
    return canceledAppointments;
}

// Setters
void Patient::setEmergencyContact(
    vector<EmergencyContact> newEmergencyContacts) {
    emergencyContacts = newEmergencyContacts;
}

void Patient::setMedicalFile(MedicalFile newMedicalFile) {
    medicalFile = newMedicalFile;
}

// Metodos da classe
void Patient::addEmergencyContact(EmergencyContact newEmergencyContact) {
    emergencyContacts.push_back(newEmergencyContact);
}

void Patient::setScheduledAppointments(
    vector<Appointment> newScheduledAppointments) {
    scheduledAppointments = newScheduledAppointments;
}

void Patient::setEndedAppointments(vector<Appointment> newEndedAppointments) {
    endedAppointments = newEndedAppointments;
}

void Patient::setCanceledAppointments(
    vector<Appointment> newCanceledAppointments) {
    canceledAppointments = newCanceledAppointments;
}

string relationToString(Relation relation) {
    switch(relation){
    case Pai:
        return "Pai";
    case Mãe:
        return "Mãe";
    case Irmão:
        return "Irmão";
    case Irmã:
        return "Irmã";
    case Avô:
        return "Avô";
    case Avó:
        return "Avó";
    case Tio:
        return "Tio";
    case Tia:
        return "Tia";
    case Sobrinho:
        return "Sobrinho";
    case Sobrinha:
        return "Sobrinha";
    case Esposo:
        return "Esposo";
    case Esposa:
        return "Esposa";
    case Filho:
        return "Filho";
    case Filha:
        return "Filha";
    default:
        return "Outro";
    }
}
