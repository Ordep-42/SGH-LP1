#ifndef PATIENT_H
#define PATIENT_H

#include "../MedicalFile.h"
#include "../Time/Schedule.h"
#include "./User.h"

using namespace std;

typedef enum relations {
    Pai,
    Mae,
    Irmao,
    Irma,
    Avou,
    Avoh,
    Tio,
    Tia,
    Sobrinho,
    Sobrinha,
    Esposo,
    Esposa,
    Filho,
    Filha,
} Relation;

struct EmergencyContact {
    string name;
    Relation relation;
    string phoneNumber;

    EmergencyContact(const string &newName, Relation newRelation,
                     const string &newPhoneNumber)
        : name(newName), relation(newRelation), phoneNumber(newPhoneNumber) {}
};

string relationToString(Relation relation);

class Patient : public User {
  private:
    vector<EmergencyContact> emergencyContacts;
    MedicalFile medicalFile;
    vector<Appointment> scheduledAppointments;
    vector<Appointment> endedAppointments;
    vector<Appointment> canceledAppointments;

  public:
    Patient(unsigned short newUserID, string newLogin, string newPassWord,
            string newName, Date newBirthDate, string newCpf, Gender newGender,
            CivilStatus newCivilStatus, string newAddress,
            string newPhoneNumber, string newEmail,
            vector<EmergencyContact> newEmergencyContacts,
            MedicalFile newMedicalFile);

    Patient() {}

    Patient(string nome, string senha) {
        this->name = nome;
        this->password = senha;
    }

    Patient(int id, string nome, string senha) {
        this->userID = id;
        this->name = nome;
        this->password = senha;
    }

    vector<EmergencyContact> getEmergencyContacts();
    MedicalFile getMedicalFile();
    vector<Appointment> getScheduledAppointments();
    vector<Appointment> getEndedAppointments();
    vector<Appointment> getCanceledAppointments();

    void addEmergencyContact(EmergencyContact newEmergencyContact);
    void removeEmergencyContact(int index);
    void makeAppointment(Appointment newAppointment);
    bool cancelScheduledAppointment(int index);

    void setEmergencyContact(vector<EmergencyContact> newEmergencyContacts);
    void setMedicalFile(MedicalFile newMedicalFile);
    void setScheduledAppointments(vector<Appointment> newScheduledAppointments);
    void setEndedAppointments(vector<Appointment> newEndedAppointments);
    void setCanceledAppointments(vector<Appointment> newCanceledAppointments);
};

// Funções auxiliares

#endif // PATIENT_H
