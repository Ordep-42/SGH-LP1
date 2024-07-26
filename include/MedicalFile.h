// User.h
#ifndef MEDICALFILE_H
#define MEDICALFILE_H
#include "./Time/Date.h"
#include <string>
#include <vector>

using namespace std;

typedef enum bloodTypes { AB, A, B, O } BloodType;

typedef enum rhFactors { Positivo, Negativo } RhFactor;

class MedicalFile {
  private:
    BloodType bloodType;
    RhFactor rhFactor;
    vector<string> allergies;
    vector<string> currentMedications;
    vector<string> vaccinationRegistry;
    // Notas e observações (comentários adicionais do pessoal médico)
    vector<string> notes;

  public:
    MedicalFile(BloodType newBloodType, RhFactor newRhFactor,
                vector<string> newAllergies,
                vector<string> newCurrentMedications,
                vector<string> newVaccinationRegistry, vector<string> newNotes);

    MedicalFile() {}

    // Getters
    BloodType getBloodType();
    RhFactor getRhFactor();
    vector<string> getAllergies();
    vector<string> getCurrentMedications();
    vector<string> getVaccinationRegistry();
    vector<string> getNotes();

    // Setters
    void setBloodType(BloodType newBloodType);
    void setRhFactor(RhFactor newRhFactor);
    void setAllergies(vector<string> newAllergies);

    // Adders
    void addCurrentMedication(string newCurrentMedication);
    void addVaccinationRegistry(string newVaccinationRegistry);
    void addNote(string newNote);
};

#endif // MEDICALFILE_H
