#include "../include/User.h"
#include <string>

using namespace std;

User::User(short newUserID, string newLogin, string newPassWord, string newName,
           Date newBirthDate, string newGender, string newCivicStatus, string newAddress,
           string newPhoneNumber, string newEmail)
    : login(newLogin), name(newName), birthDate(newBirthDate), gender(newGender),
      civicStatus(newCivicStatus), address(newAddress), phoneNumber(newPhoneNumber), email(newEmail) {}

User::User(string name, string password, string role) {
    this->name = name;
    this->password = password;
    this->role = role;
}

// Getters
string User::getLogin() { return login; }

string User::getPassword() { return password; }

string User::getRole() { return role; }

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

void User::setCivicStatus(string newCivicStatus) { civicStatus = newCivicStatus; }

void User::setAddress(string newaddress) { address = newaddress; }

void User::setPhoneNumber(string newPhoneNumber) { phoneNumber = newPhoneNumber; }

void User::setEmail(string newEmail) { email = newEmail; }
