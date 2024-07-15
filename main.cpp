#include <iostream>
#include "Date.h"
using namespace std;
int main() {
    // Testando a criação de objetos Date
    Date date1(1, 2023); // 1º de janeiro de 2023
    Date date2(32222, 2022); // 
    Date date3(31+29+31+27, 2024); // 118 dias
    // Imprimindo informações das datas
    cout << "Date 1: " << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear() << endl;
    cout << "Date 2: " << date2.getDay() << "/" << date2.getMonth() << "/" << date2.getYear() << endl;
    cout << "Date 3: " << dateToDaysBF(date3.getDay(),date3.getMonth(),date3.getYear()) << "/" << date3.getMonth() << "/" << date3.getYear() << endl;
    // Testando comparações entre datas
    cout << "Date 1 is before Date 2: " << (date1.isBeforeThan(date2) ? "true" : "false") << endl;
    cout << "Date 2 is before Date 3: " << (date2.isBeforeThan(date3) ? "true" : "false") << endl;
    // Testando o método tomorrow()
    Date tomorrowDate = date1.tomorrow();
    cout << "Tomorrow Date 1: " << tomorrowDate.getDay() << "/" << tomorrowDate.getMonth() << "/" << tomorrowDate.getYear() << endl;
    // Testando o método getDays()
    cout << "Date 1 (days): " << date1.getDays() << endl; 
    return 0;
}