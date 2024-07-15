#include "../include/Interface.h"
#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
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
      return;
    }
  }
}

void hr() {
  cout << "--------------------------------------" << endl;
}

int choiceMaker(vector<string> entries) {
  int size = 0, choice = 0; // ao invés de iniciar com 1 ou outro valor aleatório  

  for (string choice : entries) {// Dá pra somar antes
    cout << "[" << ++size << "] " << choice << endl;
  }

  hr();
  //size = size - 1; <- agora esse pedaço pôde ser descartado

  cout << "Escolha uma opção de 1 a " << size << ": ";
  cin >> choice; getchar();

  while (choice < 1 || choice > size) {
    cout << "Ops, valor inválido. Tente novamente..." << endl;
    cin >> choice; getchar();
  }
  cout << endl;

  return choice;
}

void loginInterface() {
  vector<string> login_entries;

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
  titleMaker("LOGIN");
  cout << "Digite o seu nome: \n";
  cin >> nome; getchar();
  titleMaker("LOGIN");
  cout << "Digite sua senha: \n";
  cin >> senha; getchar();

  cout << "Fazendo login...\n";
}

void HospitalInterface::createPatientInterface() {

}

void titleMaker(string title) {
  transform(title.begin(), title.end(), title.begin(), ::toupper);
  hr();
  cout << title << endl;
  hr();
}
