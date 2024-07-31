#include "../../include/HospitalDatabase/HospitalDatabase.h"
#include "../../include/Interface.h"
#include <cstdlib>
#include <iostream>
#include <map>
#include <optional>
#include <unistd.h>

void HospitalInterface::loginInterface() {
    system("clear");
    vector<string> login_entries;

    map<int, Roles::Role> roleMap = {
        {1, Roles::Patient},
        {2, Roles::Assistant},
        {3, Roles::Doctor},
        {4, Roles::Manager},
    };

    login_entries.push_back("Paciente");
    login_entries.push_back("Atendente");
    login_entries.push_back("Doutor");
    login_entries.push_back("Gestor");
    login_entries.push_back("Nenhum, voltar.");

    titleMaker("LOGIN");
    cout << "Que tipo de usuário você é?\n";
    int tipoDeUsuario = choiceMaker(login_entries);

    // 5 significa que ele decidiu sair
    if (tipoDeUsuario == 5) {
        return;
    }

    string nome;
    string senha;

    // Os getchar's *comem* os enter's
    cout << "Digite o seu nome: \n";
    cin >> nome;
    getchar();
    cout << "Digite sua senha: \n";
    cin >> senha;
    getchar();

    cout << "Fazendo login...\n";

    switch (tipoDeUsuario) {
    case 1: {
        optional<Patient> maybePatient =
            HospitalDatabase::getPatientByNameAndPassword(nome, senha);

        if (!maybePatient.has_value()) {
            cout << "Paciente invalido... Tente novamente.\n";
            sleep(1);
            return;
        }

        this->setCurrentUser(&maybePatient.value());
        this->setAccessLevel(tipoDeUsuario);
        this->setIsLogged(true);

        patientInterface();

        break;
    }
    case 2:
        attendantInterface();
        break;
    case 3: {
        optional<Doctor> maybeDoctor =
            HospitalDatabase::getDoctorByNameAndPassword(nome, senha);
        if (!maybeDoctor.has_value()) {
            cout << "Doutor invalido... Tente novamente.\n";
            sleep(1);
            return;
        }

        this->setCurrentUser(&maybeDoctor.value());
        this->setIsLogged(true);
        this->setAccessLevel(tipoDeUsuario);

        doctorInterface();
        break;
    }
    case 4: {
        optional<Manager> maybeManager =
            HospitalDatabase::getManagerByNameAndPassword(nome, senha);

        if (!maybeManager.has_value()) {
            cout << "Manager invalido... Tente novamente.\n";
            sleep(1);
            return;
        }
        this->setCurrentUser(&maybeManager.value());
        this->setAccessLevel(tipoDeUsuario);
        this->setIsLogged(true);

        managerInterface();
        break;
    }
    }

    sleep(1);
}
