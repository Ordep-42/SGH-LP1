#include "../../../include/Interface.h"
#include <cstdlib>

void HospitalInterface::attendantInterface() {
    system("clear");
    titleMaker("CENTRAL DO ATENDENTE");

    vector<string> choices;
    choices.push_back("Voltar");
    int choice = choiceMaker(choices);
    HospitalInterface::entryProgramInterface();
}
