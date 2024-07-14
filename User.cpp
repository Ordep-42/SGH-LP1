#include "User.h"
#include <iostream>
#include <string>
using namespace std;

User::User(short newUserID, string newUserName, string newPassWord, string newName, Date newBirthDate, string newGender, string newCivicStatus, string newAdress, string newPhoneNumber, string newEmail, Date newIngressDate)
: ingressDate(newIngressDate), birthDate(newBirthDate), userID(newUserID), userName(newUserName), passWord(newPassWord), name(newName), gender(newGender), civicStatus(newCivicStatus), adress(newAdress), phoneNumber(newPhoneNumber), email(newEmail) {}

// Getters
short User::getUserID() {
    return userID;
}

string User::getUserName() {
    return userName;
}

string User::getPassWord() {
    return passWord;
}

string User::getName() {
    return name;
}

Date User::getBirthDate() {
    return birthDate;
}

string User::getGender() {
    return gender;
}

string User::getCivicStatus() {
    return civicStatus;
}

string User::getAdress() {
    return adress;
}

string User::getPhoneNumber() {
    return phoneNumber;
}

string User::getEmail() {
    return email;
}

Date User::getIngressDate() {
    return ingressDate;
}

// Setters (excluding userID, userName, and ingressDate and BirthDate!!)
void User::setPassWord(string newPassWord) {
    passWord = newPassWord;
}

void User::setName(string newName) {
    name = newName;
}

void User::setGender(string newGender) {
    gender = newGender;
}

void User::setCivicStatus(string newCivicStatus) {
    civicStatus = newCivicStatus;
}

void User::setAdress(string newAdress) {
    adress = newAdress;
}

void User::setPhoneNumber(string newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void User::setEmail(string newEmail) {
    email = newEmail;
}