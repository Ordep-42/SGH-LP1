#include "../../include/Interface.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

void HospitalInterface::entryProgramInterface() {
    vector<string> initial_choices;

    int escolha = 0;

    initial_choices.push_back("Fazer login");
    initial_choices.push_back("Cadastrar-se");
    initial_choices.push_back("Sair");

    while (escolha != 3) {
        titleMaker("SISTEMA DE GERENCIAMENTO HOSPITALAR");
        escolha = choiceMaker(initial_choices);

        switch (escolha) {
        case 1:
            loginInterface();
            break;
        case 2:
            createPatientInterface();
            break;
        case 3:
            cout << "Finalizando programa...\n";
        default:
            std::exit(0);
        }
    }
}

bool HospitalInterface::assertAccessLevel(int correctAccessLevel) {
    if (this->getAccessLevel() != correctAccessLevel) {
        cout << "Interface errada! Retornando ao menu."
             << this->getAccessLevel() << " " << correctAccessLevel << endl;
        this->setIsLogged(false);
        return false;
    }
    return true;
}

int HospitalInterface::getAccessLevel() { return this->accessLevel; }

bool HospitalInterface::getIsLogged() { return this->isLogged; }

User *HospitalInterface::getCurrentUser() { return this->currentUser; }

void HospitalInterface::setAccessLevel(int newAccessLevel) {
    this->accessLevel = newAccessLevel;
}

void HospitalInterface::setIsLogged(bool newIsLogged) {
    this->isLogged = newIsLogged;
}

void HospitalInterface::setCurrentUser(User *newUser) {
    this->currentUser = newUser;
}

int choiceMaker(vector<string> entries) {
    int size = 0, choice = 0;

    for (string choice : entries) {
        cout << "[" << ++size << "] " << choice << endl;
    }

    hr();

    cout << "Escolha uma opção de 1 a " << size << ": ";
    cin >> choice;
    getchar();

    while (choice < 1 || choice > size) {
        cout << "Ops, valor inválido. Tente novamente..." << endl;
        cin >> choice;
        getchar();
    }
    cout << endl;

    return choice;
}

void hr() { cout << "--------------------------------------" << endl; }

void titleMaker(string title) {
    transform(title.begin(), title.end(), title.begin(), ::toupper);
    hr();
    cout << title << endl;
    hr();
}
