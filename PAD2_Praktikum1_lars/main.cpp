#include <iostream>

#include<travelagency.h>

using namespace std;


int main()
{
    TravelAgency travelAgency;

    char userInput = '0';

    do{
        cout << "Wie sollen die Daten eingelesen werden ?" << endl;
        cout << "( B fuer Binar und T fuer Text )" << endl;
        cin >> userInput;
        if(!cin){
            userInput = '0';
            cin.clear();
            cin.ignore(100, '\n');
        }
        if(userInput != 'B' && userInput !='T'){
            userInput = '0';
        }

    }while(userInput == '0');

    if(userInput == 'B'){
        travelAgency.readBinaryFile();
    }else{
        travelAgency.readFile();
    }
}
