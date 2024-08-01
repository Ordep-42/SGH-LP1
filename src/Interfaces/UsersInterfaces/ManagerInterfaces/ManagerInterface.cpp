#include "../../../../include/Interface.h"
#include <cstdlib>

void HospitalInterface::managerInterface() {
    system("clear");
    titleMaker("CENTRAL DO GESTOR");

    vector<string> choices;
    choices.push_back("Criar");
    choices.push_back("Listar");
    choices.push_back("Deletar");
    choices.push_back("Cadastrar");
    choices.push_back("Deslogar");
    int choice = choiceMaker(choices);

    switch (choice) {
    case 1:
        HospitalInterface::managerCreateInterface();
        break;
    case 2:
        HospitalInterface::managerListInterface();
        break;
    case 3:
        HospitalInterface::managerDeleteInterface();
    case 4:
        HospitalInterface::managerRegisterInterface();
    case 5:
        this->setAccessLevel(0);
        this->setIsLogged(false);
        this->setCurrentUser(nullptr);
        HospitalInterface::entryProgramInterface();
    }
}
