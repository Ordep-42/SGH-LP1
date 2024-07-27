#include "../../include/HospitalDatabase/HospitalDatabase.h"
#include "../../include/Interface.h"
#include "../../include/Users/Patient.h"
#include <iostream>
#include <unistd.h>

void HospitalInterface::createPatientInterface() {
    titleMaker("CRIANDO NOVO PACIENTE");

    string nome;
    string senha;
    cout << "Digite seu primeiro nome: " << endl;
    cin >> nome;
    getchar();

    cout << "Digite sua senha: " << endl;
    cin >> senha;
    getchar();

    Patient novoPaciente = Patient(nome, senha);

    HospitalDatabase::createPatient(novoPaciente);

    cout << "Paciente criado com sucesso!" << endl;
    sleep(1);
}
