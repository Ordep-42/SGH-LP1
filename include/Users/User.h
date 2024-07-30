// User.h
#ifndef USER_H
#define USER_H
// #include <iostream>
#include "../Time/Date.h"
#include <string>
#include <vector>

namespace Roles {
typedef enum roles { Admin, Manager, Doctor, Assistant, Patient } Role;
}

typedef enum genders { Masculino, Feminino, Outro } Gender;

typedef enum civilStatus { Solteiro, Casado, Divorciado, Viuvo } CivilStatus;

using namespace std;

class User {
  protected:
    // MostReleants
    unsigned short userID;
    string login;
    string password;
    string name;
    Roles::Role role;

    // Less relevants:
    Date birthDate;
    string cpf;
    Gender gender;
    CivilStatus civilStatus;
    string address;
    string phoneNumber; // como tratar?
    string email;
   

  public:
    User(unsigned short newUserID, string newLogin, string newPassWord,
         string newName, Date newBirthDate, Gender newGender,
         CivilStatus newCivilStatus, string newAddress, string newPhoneNumber,
         string newEmail);

    User(string name, string password, Roles::Role role);

    User() {}

    unsigned short getUserID();
    string getLogin();
    string getPassword();
    string getName();
    Date getBirthDate();
    string getCpf();
    Gender getGender();
    CivilStatus getCivilStatus();
    string getAddress();
    string getPhoneNumber();
    string getEmail();
    Roles::Role getRole();
    Date getIngressDate();

    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setBirthDate(Date newBirthDate);
    void setCpf(string newCpf);
    void setGender(Gender newGender);
    void setCivilStatus(CivilStatus newCivilStatus);
    void setAddress(string newAddress);
    void setPhoneNumber(string newPhoneNumber);
    void setEmail(string newEmail);
    void setRole(Roles::Role role);

    virtual ~User() = default;
    virtual void whoAmI() {}
};

// Funções auxiliares

#endif // USER_H
