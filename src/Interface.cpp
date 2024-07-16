#include "../include/Interface.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
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

// Todas as interfaces fazem parte dessa classe
void HospitalInterface::loginInterface() {
  vector<string> login_entries;

  map<int, string> roleMap = {
      {1, "paciente"},
      {2, "atendente"},
      {3, "doutor"},
      {4, "gestor"},
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
  titleMaker("LOGIN");
  cout << "Digite o seu nome: \n";
  cin >> nome;
  getchar();
  cout << "Digite sua senha: \n";
  cin >> senha;
  getchar();

  cout << "Fazendo login...\n";

  User goingToLogUser = User(nome, senha, roleMap.find(tipoDeUsuario)->second);

  /*if (!isValidUser(goingToLogUser)) {*/
  /*  cout << "Usuário inválido. Tente novamente" << endl;
   *  sleep(1);
   *  return;*/
  /*}*/

  this->setAccessLevel(tipoDeUsuario);
  this->setCurrentUser(&goingToLogUser);
  this->setIsLogged(true);

  switch (tipoDeUsuario) {
  case 1:
    patientInterface();
  case 2:
    attendantInterface();
  case 3:
    doctorInterface();
  case 4:
    managerInterface();
  }

  sleep(1);
}

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

  User novoPaciente = User(nome, senha, "paciente");

  // #TODO
  // É preciso implementar uma classe pra encapsular o database
  // Talvez essa classe também fique responsável pelo isValidPassword(string)
  // mencionada na Linha 87
  // HospitalDatabase::CreateUser(novoPaciente);
  cout << "Usuário criado com sucesso!" << endl;
  sleep(1);
}

void HospitalInterface::patientInterface() {
  if (!this->assertAccessLevel(1)) {
    HospitalInterface::entryProgramInterface();
  }

  titleMaker("CENTRAL DO PACIENTE");

  vector<string> choices;
  choices.push_back("Voltar");
  int choice = choiceMaker(choices);
  HospitalInterface::entryProgramInterface();
}

void HospitalInterface::attendantInterface() {
  if (!this->assertAccessLevel(2)) {
    HospitalInterface::entryProgramInterface();
  }

  titleMaker("CENTRAL DO ATENDENTE");

  vector<string> choices;
  choices.push_back("Voltar");
  int choice = choiceMaker(choices);
  HospitalInterface::entryProgramInterface();
}

void HospitalInterface::doctorInterface() {
  if (!this->assertAccessLevel(3))
    HospitalInterface::entryProgramInterface();

  titleMaker("CENTRAL DO DOUTOR");

  vector<string> choices;
  choices.push_back("Voltar");
  int choice = choiceMaker(choices);
  HospitalInterface::entryProgramInterface();
}

void HospitalInterface::managerInterface() {
  if (!this->assertAccessLevel(4)) {
    HospitalInterface::entryProgramInterface();
  }

  titleMaker("CENTRAL DO GESTOR");

  vector<string> choices;
  choices.push_back("Voltar");
  int choice = choiceMaker(choices);
  HospitalInterface::entryProgramInterface();
}

bool HospitalInterface::assertAccessLevel(int correctAccessLevel) {
  if (this->getAccessLevel() != correctAccessLevel) {
    cout << "Interface errada! Retornando ao menu." << this->getAccessLevel()
         << " " << correctAccessLevel << endl;
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
