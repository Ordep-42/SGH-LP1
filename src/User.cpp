#include "../include/User.h"
#include <string>

using namespace std;

User::User(short newUserID, string newUserName, string newPassWord,
           string newName, Date newBirthDate, string newGender,
           string newCivicStatus, string newAdress, string newPhoneNumber,
           string newEmail, Date newIngressDate)
    : ingressDate(newIngressDate), birthDate(newBirthDate),
      password(newPassWord), name(newName), gender(newGender),
      civicStatus(newCivicStatus), adress(newAdress),
      phoneNumber(newPhoneNumber), email(newEmail) {}

User::User(string name, string password, string role) {
    this->name = name;
    this->password = password;
    this->role = role;
}

// Getters

string User::getRole() { return role; }

string User::getPassword() { return password; }

string User::getName() { return name; }

Date User::getBirthDate() { return birthDate; }

string User::getGender() { return gender; }

string User::getCivicStatus() { return civicStatus; }

string User::getAdress() { return adress; }

string User::getPhoneNumber() { return phoneNumber; }

string User::getEmail() { return email; }

Date User::getIngressDate() { return ingressDate; }

// Setters (excluding userID, userName, and ingressDate and BirthDate!!)
void User::setPassword(string newPassWord) { password = newPassWord; }

void User::setName(string newName) { name = newName; }

void User::setGender(string newGender) { gender = newGender; }

void User::setCivicStatus(string newCivicStatus) {
    civicStatus = newCivicStatus;
}

void User::setAdress(string newAdress) { adress = newAdress; }

void User::setPhoneNumber(string newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void User::setEmail(string newEmail) { email = newEmail; }
