#ifndef PATIENT_H
#define PATIENT_H
#include "MedicalFile.h"
#include "Schedule.h"

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
    vector<Appointment> scheduledAppointments;
    vector<Appointment> endedAppointments;
    vector<Appointment> canceledAppointments;

  public:
    Patient(unsigned short newUserID, string newLogin, string newPassWord,
            string newName, Date newBirthDate, string newCpf, Gender newGender,
            CivilStatus newCivilStatus, string newAddress,
            string newPhoneNumber, string newEmail,
            vector<EmergencyContact> newEmergencyContacts, MedicalFile newMedicalFile);

    Patient() {}

    vector<EmergencyContact> getEmergencyContacts();
    MedicalFile getMedicalFile();
    vector<Appointment> getScheduledAppointments();
    vector<Appointment> getEndedAppointments();
    vector<Appointment> getCanceledAppointments();
    
    void addEmergencyContact(EmergencyContact newEmergencyContact);
    void makeAppointment(Appointment newAppointment);
    bool cancelScheduledAppointment(Appointment appointment);

    void setEmergencyContact(vector<EmergencyContact> newEmergencyContacts);
    void setMedicalFile(MedicalFile newMedicalFile);
    void setScheduledAppointments(vector<Appointment> newScheduledAppointments);
    void setEndedAppointments(vector<Appointment> newEndedAppointments);
    void setCanceledAppointments(vector<Appointment> newCanceledAppointments);
};

// Funções auxiliares

#endif // PATIENT_H
