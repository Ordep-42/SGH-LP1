#include "../include/HospitalDatabase/HospitalDatabase.h"
#include "../include/Interface.h"
#include <sqlite3.h>

int main() {
    HospitalDatabase();
    HospitalInterface interface = HospitalInterface();
    interface.entryProgramInterface();
    return 0;
}
