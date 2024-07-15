#include "../include/utils/text.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> initial_choices;
  initial_choices.push_back("Fazer login");
  initial_choices.push_back("Cadastrar-se");
  initial_choices.push_back("Sair");

  int escolha = choices(initial_choices);

  hr();
  cout << "SISTEMA DE GERENCIAMENTO HOSPITALAR" << endl;

  switch (escolha) {
  case 1:
    cout << "Fazendo login...\n";
    // login();
    break;
  case 2:
    cout << "Iniciando cadastro..." << escolha << "\n";
    break;
    // register();
  case 3:
    cout << "Finalizando programa..." << escolha << "\n";
    return 0;
  default:
    return 1;
  }

  return 0;
}
