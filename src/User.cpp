#include "../include/User.h"
#include <string>

using namespace std;

User::User(short newUserID, string newLogin, string newPassWord, string newName,
           Date newBirthDate, Gender newGender, CivilStatus newCivilStatus, string newAddress,
           string newPhoneNumber, string newEmail)
    : login(newLogin), name(newName), birthDate(newBirthDate), gender(newGender),
      civilStatus(newCivilStatus), address(newAddress), phoneNumber(newPhoneNumber), email(newEmail) {}

User::User(string name, string password, Role role) {
    this->name = name;
    this->password = password;
    this->role = role;
}

// Getters
string User::getLogin() { return login; }

string User::getPassword() { return password; }

Role User::getRole() { return role; }

string User::getName() { return name; }

Date User::getBirthDate() { return birthDate; }

Gender User::getGender() { return gender; }

CivilStatus User::getCivilStatus() { return civilStatus; }

string User::getAddress() { return address; }

string User::getPhoneNumber() { return phoneNumber; }

string User::getEmail() { return email; }

// Setters (a menos de userID, e BirthDate!!)
void User::setLogin(string newLogin) { login = newLogin; }

void User::setPassword(string newPassWord) { password = newPassWord; }

void User::setName(string newName) { name = newName; }

void User::setGender(Gender newGender) { gender = newGender; }

void User::setCivilStatus(CivilStatus newCivilStatus) { civilStatus = newCivilStatus; }

void User::setPhoneNumber(string newPhoneNumber) { phoneNumber = newPhoneNumber; }

void User::setEmail(string newEmail) { email = newEmail; }
