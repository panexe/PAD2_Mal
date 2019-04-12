#include <iostream>

#include "travelagency.h"

using namespace std;

int main()
{

    TravelAgency travelagency;
    travelagency.readFile();

    vector<string> objekt_data;
    objekt_data.push_back("DI");
    objekt_data.push_back("DA");
    objekt_data.push_back("RMV");


    travelagency.createBooking('F',double(309.16),"20190505","20190506",1,objekt_data);
    travelagency.printNumerals();
    return 0;
}
