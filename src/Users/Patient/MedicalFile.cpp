#include "../../../include/MedicalFile.h"
#include <string>
#include <vector>
using namespace std;

MedicalFile::MedicalFile(BloodType newBloodType, RhFactor newRhFactor,
                         vector<string> newAllergies,
                         vector<string> newCurrentMedications,
                         vector<string> newVaccinationRegistry,
                         vector<string> newNotes)
    : bloodType(newBloodType), rhFactor(newRhFactor), allergies(newAllergies),
      currentMedications(newCurrentMedications),
      vaccinationRegistry(newVaccinationRegistry), notes(newNotes) {}

// Getters
BloodType MedicalFile::getBloodType() { return bloodType; }

RhFactor MedicalFile::getRhFactor() { return rhFactor; }

vector<string> MedicalFile::getAllergies() { return allergies; }

vector<string> MedicalFile::getCurrentMedications() {
    return currentMedications;
}

vector<string> MedicalFile::getVaccinationRegistry() {
    return vaccinationRegistry;
}

vector<string> MedicalFile::getNotes() { return notes; }

// Setters
void MedicalFile::setBloodType(BloodType newBloodType) {
    bloodType = newBloodType;
}

void MedicalFile::setRhFactor(RhFactor newRhFactor) { rhFactor = newRhFactor; }

void MedicalFile::setAllergies(vector<string> newAllergies) {
    allergies = newAllergies;
}

// Adders (Como são arrays, é melhor método pra adicionar do que setar)
void MedicalFile::addCurrentMedication(string newCurrentMedication) {
    currentMedications.push_back(newCurrentMedication);
}

void MedicalFile::addVaccinationRegistry(string newVaccinationRegistry) {
    vaccinationRegistry.push_back(newVaccinationRegistry);
}

void MedicalFile::addNote(string newNote) { notes.push_back(newNote); }
