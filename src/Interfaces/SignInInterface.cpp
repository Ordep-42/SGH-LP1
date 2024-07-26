
#include "../../include/Interface.h"
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

    // #TODO
    /*if (!isValidPassword(senha)) {*/
    /*  cout << "Senha inválida. Tente novamente." << endl;
     *  sleep(1);
     *  */
    /*}*/

    User novoPaciente = User(nome, senha, Roles::Patient);

    // #TODO
    // É preciso implementar uma classe pra encapsular o database
    // Talvez essa classe também fique responsável pelo isValidPassword(string)
    // mencionada na Linha 87
    // HospitalDatabase::CreateUser(novoPaciente);
    cout << "Usuário criado com sucesso!" << endl;
    sleep(1);
}
