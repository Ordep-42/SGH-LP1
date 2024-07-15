// Patient.h
#ifndef PATIENT_H
#define PATIENT_H
#include "Date.h"
#include "MedicalFile.h"
#include "User.h"
#include <string>
#include <vector>

using namespace std;

struct EmergencyContact {
  string name;
  string relation;
  string phoneNumber;

  EmergencyContact(const string &newName, const string &newRelation,
                   const string &newPhoneNumber)
      : name(newName), relation(newRelation), phoneNumber(newPhoneNumber) {}
};

struct PatientData {
  string name;
  const Date birthDate;
  string sex; // vai que ne, sla...
  string gender;
  string civicStatus;

  // vector<appointment> appointmentRegistry;

  PatientData(string newName, const Date &newBirthDate, string newSex,
              string newGender, string newCivicStatus)
      : name(newName), birthDate(newBirthDate), sex(newSex), gender(newGender),
        civicStatus(newCivicStatus) {}
};

class Patient {
private:
  PatientData data;
  vector<EmergencyContact> emergencyContacts;
  User user;
  MedicalFile medicalFile;

  // registro de pagamentos e etc.

  // Pendente
public:
};

// Funções auxiliares

#endif // PATIENT_H
