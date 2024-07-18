#include "../include/User.h"
#include <string>

using namespace std;

User::User(short newUserID, string newUserName, string newPassWord, string newName,
           Date newBirthDate, string newGender, string newCivicStatus, string newAddress,
           string newPhoneNumber, string newEmail)
    : name(newName), birthDate(newBirthDate), gender(newGender), civicStatus(newCivicStatus),
      address(newAddress), phoneNumber(newPhoneNumber), email(newEmail) {}

User::User(string newName, string newPassword, string newRole) {
    this->name = newName;
    this->password = newPassword;
    this->role = newRole;
}

// Getters

string User::getRole() { return role; }

string User::getPassword() { return password; }

string User::getName() { return name; }

Date User::getBirthDate() { return birthDate; }

string User::getGender() { return gender; }

string User::getCivicStatus() { return civicStatus; }

string User::getAddress() { return address; }

string User::getPhoneNumber() { return phoneNumber; }

string User::getEmail() { return email; }

// Setters (excluding userID, userName, and ingressDate and BirthDate!!)
void User::setPassword(string newPassWord) { password = newPassWord; }

void User::setName(string newName) { name = newName; }

void User::setGender(string newGender) { gender = newGender; }

void User::setCivicStatus(string newCivicStatus) {
    civicStatus = newCivicStatus;
}

void User::setAddress(string newaddress) { address = newaddress; }

void User::setPhoneNumber(string newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void User::setEmail(string newEmail) { email = newEmail; }
