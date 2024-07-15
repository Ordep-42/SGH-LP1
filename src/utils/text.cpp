#include "../../include/utils/text.h"
#include <iostream>
#include <vector>

void hr() {
  std::cout << "--------------------------------------" << std::endl;
}

// Cria opções para se escolher a partir de uma lista de strings
int choices(std::vector<std::string> entries) {
  int size = 1;
  int choice = entries.size() + 2;

  hr();
  for (std::string choice : entries) {
    std::cout << size++ << ". " << choice << std::endl;
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
