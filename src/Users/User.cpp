#include "../../include/Users/User.h"

using namespace std;

User::User(unsigned short newUserID, string newLogin, string newPassWord,
           string newName, string newCpf, Date newBirthDate, Gender newGender,
           CivilStatus newCivilStatus, string newAddress, string newPhoneNumber,
           string newEmail)
    : userID(newUserID), login(newLogin), name(newName), cpf(newCpf),
      birthDate(newBirthDate), gender(newGender), civilStatus(newCivilStatus),
      address(newAddress), phoneNumber(newPhoneNumber), email(newEmail) {}

User::User(string name, string password, Roles::Role role) {
    this->name = name;
    this->password = password;
    this->role = role;
}

// Getters
unsigned short User::getUserID() { return userID; }

string User::getLogin() { return login; }

string User::getPassword() { return password; }

Roles::Role User::getRole() { return role; }

string User::getName() { return name; }

Date User::getBirthDate() { return birthDate; }

string User::getCpf() { return cpf; }

Gender User::getGender() { return gender; }

CivilStatus User::getCivilStatus() { return civilStatus; }

string User::getAddress() { return address; }

string User::getPhoneNumber() { return phoneNumber; }

string User::getEmail() { return email; }

// Setters (a menos de userID!!)
void User::setLogin(string newLogin) { login = newLogin; }

void User::setPassword(string newPassWord) { password = newPassWord; }

void User::setName(string newName) { name = newName; }

void User::setBirthDate(Date newBirthDate) { birthDate = newBirthDate; }

void User::setCpf(string newCpf) { cpf = newCpf; }

void User::setGender(Gender newGender) { gender = newGender; }

void User::setCivilStatus(CivilStatus newCivilStatus) {
    civilStatus = newCivilStatus;
}

void User::setAddress(string newAddress) { address = newAddress; }

void User::setPhoneNumber(string newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void User::setEmail(string newEmail) { email = newEmail; }

string civilStatusToString(CivilStatus civilStatus) {
    switch (civilStatus) {
    case Solteiro:
        return "Solteiro";
    case Casado:
        return "Casado";
    case Divorciado:
        return "Divorciado";
    case Viuvo:
        return "Viuvo";
    default:
        return "Inválido";
    }
}

string genderToString(Gender gender) {
    switch (gender) {
    case Masculino:
        return "Masculino";
    case Feminino:
        return "Feminino";
    default:
        return "Outro";
    }
}