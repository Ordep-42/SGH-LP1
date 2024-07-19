#include "../include/MedicalFile.h"
#include <string>
using namespace std;

MedicalFile::MedicalFile(vector<string> newCurrentMedications,
                         string newBloodType, vector<string> newAllergies,
                         vector<string> newVaccinationRegistry,
                         vector<string> newNotes, string newSex)
    : currentMedications(newCurrentMedications), bloodType(newBloodType),
      sex(newSex), allergies(newAllergies),
      vaccinationRegistry(newVaccinationRegistry), notes(newNotes) {}

// Getters
vector<string> MedicalFile::getCurrentMedications() {
    return currentMedications;
}

string MedicalFile::getBloodType() { return bloodType; }

vector<string> MedicalFile::getAllergies() { return allergies; }

vector<string> MedicalFile::getVaccinationRegistry() {
    return vaccinationRegistry;
}

vector<string> MedicalFile::getNotes() { return notes; }

// Setters
void MedicalFile::setBloodType(string newBloodType) {
    bloodType = newBloodType;
}

void MedicalFile::setAllergies(vector<string> newAllergies) {
    allergies = newAllergies;
}

/*
// You can implement these methods if needed, but it's generally recommended
// to use add/remove methods for vectors to avoid replacing the entire vector:
// i was thinking in the same :PP

void MedicalFile::setCurrentMedications(vector<string> newCurrentMedications) {
    currentMedications = newCurrentMedications;
}

void MedicalFile::setVaccinationRegistry(vector<string> newVaccinationRegistry)
{ vaccinationRegistry = newVaccinationRegistry;
}

void MedicalFile::setNotes(vector<string> newNotes) {
    notes = newNotes;
}
*/
