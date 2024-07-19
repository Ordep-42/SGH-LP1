#include "../include/Patient.h"

using namespace std;

Patient::Patient(unsigned short newUserID, string newLogin, string newPassWord,
                 string newName, Date newBirthDate, string newCpf,
                 Gender newGender, CivilStatus newCivilStatus,
                 string newAddress, string newPhoneNumber, string newEmail,
                 Role role, vector<EmergencyContact> newEmergencyContacts,
                 MedicalFile newMedicalFile)
    : User(newUserID, newLogin, newPassWord, newName, newBirthDate, newCpf,
           newGender, newCivilStatus, newAddress, newPhoneNumber, newEmail),
      emergencyContacts(newEmergencyContacts), medicalFile(newMedicalFile) {}

// Getters
vector<EmergencyContact> Patient::getEmergencyContacts() { return emergencyContacts; }

MedicalFile Patient::getMedicalFile() { return medicalFile; }

// Setters
void Patient::setEmergencyContact(EmergencyContact newEmergencyContact) {
    emergencyContacts.push_back(newEmergencyContact);
}

void Patient::setMedicalFile(MedicalFile newMedicalFile) { medicalFile = newMedicalFile; }