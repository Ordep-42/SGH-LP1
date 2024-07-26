#include "../../../include/Interface.h"

void HospitalInterface::managerInterface() {
    titleMaker("CENTRAL DO GESTOR");

    vector<string> choices;
    choices.push_back("Voltar");
    int choice = choiceMaker(choices);
    HospitalInterface::entryProgramInterface();
}
