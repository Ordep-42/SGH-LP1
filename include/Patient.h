#ifndef PATIENT_H
#define PATIENT_H
#include "MedicalFile.h"
#include "User.h"
#include <string>
#include <vector>

using namespace std;

typedef enum relations {
    Pai, Mãe, Irmão, Irmã, Avô, Avó, 
    Tio, Tia, Sobrinho, Sobrinha,
    Esposo, Esposa, Filho, Filha, Outro // Não consegui pensar em mais nenhum e acho q ta bom!
} Relation;
struct EmergencyContact {
    string name;
    Relation relation;
    string phoneNumber;

    EmergencyContact(const string &newName, Relation newRelation,
                     const string &newPhoneNumber)
        : name(newName), relation(newRelation), phoneNumber(newPhoneNumber) {}
};

class Patient : public User {
  private:
    vector<EmergencyContact> emergencyContacts;
    MedicalFile medicalFile;

    // registro de pagamentos e etc.

  public:
    Patient(unsigned short newUserID, string newLogin, string newPassWord,
            string newName, Date newBirthDate, string newCpf, Gender newGender,
            CivilStatus newCivilStatus, string newAddress,
            string newPhoneNumber, string newEmail, Role role,
            vector<EmergencyContact> newEmergencyContacts, MedicalFile newMedicalFile);

    vector<EmergencyContact> getEmergencyContacts();
    MedicalFile getMedicalFile();

    void setEmergencyContact(EmergencyContact newEmergencyContacts);
    void setMedicalFile(MedicalFile newMedicalFile);
};

// Funções auxiliares

#endif // PATIENT_H
