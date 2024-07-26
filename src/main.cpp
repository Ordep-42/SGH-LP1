#include "../include/Interface.h"
#include <sqlite3.h>

int main() {
    HospitalInterface interface = HospitalInterface();
    interface.entryProgramInterface();
    return 0;
}
