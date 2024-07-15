#include "../include/Interface.h"
#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

void HospitalInterface::entryProgramInterface() {
  vector<string> initial_choices;

  int escolha = 4;

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

void HospitalInterface::hr() {
  std::cout << "--------------------------------------" << std::endl;
}

int HospitalInterface::choiceMaker(std::vector<std::string> entries) {
  int size = 1;
  int choice = entries.size() + 2;

  for (std::string choice : entries) {
    std::cout << "[" << size++ << "] " << choice << std::endl;
  }
  hr();

  size = size - 1;

  std::cout << "Escolha uma opção de 1 a " << size << ": ";
  while (choice < 1 || choice > size) {
    std::cin >> choice;
    if (choice < 1 || choice > size) {
      std::cout << "Ops, valor inválido. Tente novamente..." << std::endl;
    }
  }
  std::cout << std::endl;
  return choice;
}

void HospitalInterface::loginInterface() {
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

  titleMaker("LOGIN");
  cout << "Digite o seu nome: \n";
  cin >> nome;
  titleMaker("LOGIN");
  cout << "Digite sua senha: \n";
  cin >> senha;

  cout << "Fazendo login...\n";
}

void HospitalInterface::createPatientInterface() {}

void HospitalInterface::titleMaker(string title) {
  transform(title.begin(), title.end(), title.begin(), ::toupper);
  hr();
  cout << title << endl;
  hr();
}
