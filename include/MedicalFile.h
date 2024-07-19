// User.h
#ifndef MEDICALFILE_H
#define MEDICALFILE_H
#include "Date.h"
#include <string>
#include <vector>

using namespace std;

class MedicalFile {
  private:
    vector<string> currentMedications;
    string bloodType; //; vai que ne, sla...
    string sex;
    vector<string> allergies;
    vector<string> vaccinationRegistry;
    // Notas e observações (comentários adicionais do pessoal médico)
    vector<string> notes;

  public:
    MedicalFile(vector<string> newCurrentMedications, string newBloodType,
                vector<string> newAllergies,
                vector<string> newVaccinationRegistry, vector<string> newNotes,
                string newSex);

    // métodos get:
    vector<string> getCurrentMedications();
    string getBloodType();
    vector<string> getAllergies();
    vector<string> getVaccinationRegistry();
    vector<string> getNotes();

    // métodos set:
    void setBloodType(string newBloodType);
    void setAllergies(vector<string> newAllergies);

    /* Será melhor trabalhar nesses com métodos:
    void setCurrentMedications(vector<string> newCurrentMedications);
    void setVaccinationRegistry(vector<string> newVaccinationRegistry);
    void setNotes(vector<string> newNotes); */
};

#endif // MEDICALFILE_H
