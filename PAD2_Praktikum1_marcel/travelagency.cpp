#include "travelagency.h"

#include <iostream>
#include <fstream>
#include <string>

TravelAgency::TravelAgency()
{

}



std::vector<std::string> spalteString(std::string a, char Trennstrich){
    // Splits a string into substring devided by a sperator
    // input : string:in (the string that gets split)
    // input : char:seperator (the char that seperates the substrings)
    // return : vector<string> (the segments)


    std::vector<unsigned int> spalte_Positionen;
    std::vector<std::string> Return;

    // get positions of seperators
    for (unsigned int i = 0; i < a.length(); i++){
        if(a[i] == Trennstrich){
            spalte_Positionen.push_back(i);
        }
    }

    // case theres no seperator in the in-string
    if(spalte_Positionen.size() == 0){
        Return.push_back(a);
        return Return;
    }

    // push substrings into ret-vector
    Return.push_back(a.substr(0,spalte_Positionen[0]));

    for (unsigned int i = 0; i< spalte_Positionen.size(); i++){
        Return.push_back(a.substr(spalte_Positionen[i] +1,spalte_Positionen[i+1] - spalte_Positionen[i] - 1));
    }

    return Return;


}

void TravelAgency::readFile()
{
    string Zeile;
    ifstream Textdatei("bookings.txt");

    int flugbuchungen_anzahl{0};
    int mietwagenbuchungen_anzahl{0};
    int hotelreservierungen_anzahl{0};

    double flugbuchungen_wert{0};
    double mietwagenbuchungen_wert{0};
    double hotelreservierungen_wert{0};


    vector<string> Zeilen;


    if(!Textdatei){
        cerr << "Datei kann nicht geöffnet werden" << endl;
    }

    while(getline(Textdatei, Zeile)){
        Zeilen.push_back(Zeile);
    }

    vector<vector<string>> Daten;

    for (unsigned int i = 0; i < Zeilen.size(); i++){
            std::vector<std::string> spalten = spalteString(Zeilen[i],'|');
            Daten.push_back(spalten);
    }


    for(int i = 0; i < Daten.size(); i++){
        if(Daten[i][0][0] == 'F'){




            long id = stol(Daten[i][1]);
            double price = stod(Daten[i][2]);
            string fromDate = Daten[i][3];
            string toDate = Daten[i][4];
            string fromDest = Daten[i][5];
            string toDest = Daten[i][6];
            string airline = Daten[i][7];

            flugbuchungen_anzahl++;

            flugbuchungen_wert += price;

            FlightBooking flightbooking(id,price, fromDate, toDate, fromDest, toDest, airline);

            flightBookings.push_back(&flightbooking);



        }

        if(Daten[i][0][0] == 'H'){


            long id = stol(Daten[i][1]);
            double price = stod(Daten[i][2]);
            string fromDate = Daten[i][3];
            string toDate = Daten[i][4];
            string hotel = Daten[i][5];
            string town = Daten[i][6];

            hotelreservierungen_anzahl++;

            hotelreservierungen_wert += price;

            HotelBooking hotelbooking(id,price, fromDate, toDate, hotel, town);

            hotelBookings.push_back(&hotelbooking);


        }

        if(Daten[i][0][0] == 'R'){


            long id = stol(Daten[i][1]);
            double price = stod(Daten[i][2]);
            string fromDate = Daten[i][3];
            string toDate = Daten[i][4];
            string pickupLocation = Daten[i][5];
            string returnLocation = Daten[i][6];
            string company = Daten[i][7];

            mietwagenbuchungen_anzahl++;

            mietwagenbuchungen_wert += price;

            RentalCarReservation rentalcarreservation(id,price, fromDate, toDate, pickupLocation, returnLocation, company);

            rentalCarReservations.push_back(&rentalcarreservation);


        }
    }

    cout << "Es wurden " << flugbuchungen_anzahl  << " Flugbuchungen im Wert von " << flugbuchungen_wert << " Euro,\n" << mietwagenbuchungen_anzahl << " Mietwagenbuchungen im Wert von " << mietwagenbuchungen_wert << " Euro \nund " << hotelreservierungen_anzahl << " Hotelreservierungen im Wert von " << hotelreservierungen_wert << " Euro angelegt." << endl << endl;





}
struct Daten_fullen_flightbooking{
    long id;
    double price;
    string fromDate;
    string toDate;
    string fromDest;
    string toDest;
    string airline;

    Daten_fullen_flightbooking(long id, double price, string fromDate, string toDate, string fromDest, string toDest, string airline){
        this->id = id;
        this->price = price;
        this->fromDate = fromDate;
        this-> toDate = toDate;
        this->fromDest = fromDest;
        this->toDest = toDest;
        this->airline = airline;
    }
};

struct Daten_fullen_hotelbooking{
    long id;
    double price;
    string fromDate;
    string toDate;
    string hotel;
    string town;


    Daten_fullen_hotelbooking(long id, double price, string fromDate, string toDate, string hotel, string town){
        this->id = id;
        this->price = price;
        this->fromDate = fromDate;
        this-> toDate = toDate;
        this->hotel = hotel;
        this->town = town;
    }
};

struct Daten_fullen_rentalcarbooking{
    long id;
    double price;
    string fromDate;
    string toDate;
    string pickupLocation;
    string retLocation;
    string company;

    Daten_fullen_rentalcarbooking(long id, double price, string fromDate, string toDate, string pickupLocation, string retLocation, string company){
        this->id = id;
        this->price = price;
        this->fromDate = fromDate;
        this-> toDate = toDate;
        this->pickupLocation = pickupLocation;
        this->retLocation = retLocation;
        this->company = company;
    }
};

void TravelAgency::readBinaryFile()
{
    ifstream eingabe;
    eingabe.open("bookingsBinary.bin", ios::in | ios::binary);
    vector<Daten_fullen_flightbooking> Daten1;
    vector<Daten_fullen_hotelbooking> Daten2;
    vector<Daten_fullen_rentalcarbooking> Daten3;

    int flugbuchungen_anzahl{0};
    double flugbuchungen_wert{0};

    int hotelreservierungen_anzahl{0};
    double hotelreservierungen_wert{0};

    int mietwagenbuchungen_anzahl{0};
    double mietwagenbuchungen_wert{0};

    if(eingabe.is_open()){

        int size{0};
        int aktuell{0};

        eingabe.seekg(0,ios::end);
        size = (int)eingabe.tellg();

        eingabe.seekg(0, ios::beg);

        aktuell = (int)eingabe.tellg();


        while(aktuell < size && aktuell >= 0){
            char letter{0};
            long id{0};
            double price{0};
            char fromDate[9]{0};
            char toDate[9]{0};

            char fromDest[4]{0};
            char toDest[4]{0};
            char airline[16]{0};

            char hotel[16]{0};
            char town[16]{0};

            char pickupLocation[16]{0};
            char retLocation[16]{0};
            char company[16]{0};

            eingabe.read((char*)&letter, sizeof (char));

            eingabe.read((char*)&id,sizeof (long));
            eingabe.read((char*)&price,sizeof (double));
            eingabe.read((char*)&fromDate,sizeof (char)*8);
            eingabe.read((char*)&toDate,sizeof (char)*8);

            if(letter == 'F'){
                eingabe.read((char*)&fromDest,sizeof (char)*3);
                eingabe.read((char*)&toDest,sizeof (char)*3);
                eingabe.read((char*)&airline,sizeof (char)*15);


                Daten1.push_back(Daten_fullen_flightbooking(id, price, fromDate, toDate, fromDest, toDest, airline));


            }

            if(letter == 'H'){
                eingabe.read((char*)&hotel,sizeof (char)*15);
                eingabe.read((char*)&town,sizeof (char)*15);

                Daten2.push_back(Daten_fullen_hotelbooking(id, price, fromDate, toDate, hotel, town));
            }

            if(letter == 'R'){
                eingabe.read((char*)&pickupLocation, sizeof (char)*15);
                eingabe.read((char*)&retLocation, sizeof (char)*15);
                eingabe.read((char*)&company, sizeof (char)*15);

                Daten3.push_back(Daten_fullen_rentalcarbooking(id, price, toDate, fromDate, pickupLocation, retLocation, company));
            }

            aktuell = eingabe.tellg();







        }
        eingabe.close();

    }else{
        cout << "Datei konnte nicht geoeffnet werden!" << endl;
        return;
    }


    for(int i = 0; i < Daten1.size(); i++){
        flugbuchungen_anzahl++;
        this->flightBookings.push_back(new FlightBooking(Daten1[i].id, Daten1[i].price, Daten1[i].fromDate,Daten1[i].toDate, Daten1[i].fromDest, Daten1[i].toDest, Daten1[i].airline));
    }

    for(int i = 0; i < Daten2.size(); i++){
        hotelreservierungen_anzahl++;
        this->hotelBookings.push_back(new HotelBooking(Daten2[i].id, Daten2[i].price, Daten2[i].fromDate,Daten2[i].toDate, Daten2[i].hotel, Daten2[i].town));
    }

    for(int i = 0; i < Daten3.size(); i++){
        mietwagenbuchungen_anzahl++;
        this->rentalCarReservations.push_back(new RentalCarReservation(Daten3[i].id, Daten3[i].price, Daten3[i].fromDate,Daten3[i].toDate, Daten3[i].pickupLocation, Daten3[i].retLocation, Daten3[i].company));
    }




    int max = 0;

    for(int i = 0; i < this->flightBookings.size(); i++){
        flugbuchungen_wert += flightBookings[i]->getPrice();
        if(this->flightBookings[i]->getPrice() > this->flightBookings[max]->getPrice()){
            max = i;

        }
    }

    cout << "Der Teuerste Flug (ID:" << flightBookings[max]->getId() << "): Vom " << flightBookings[max]->getFromDate() << " bis " << flightBookings[max]->getToDate() << " von " << flightBookings[max]->getFromDest() << " nach " << flightBookings[max]->getToDest() << "\nmit " << flightBookings[max]->getAirline() << " zum Preis von " << flightBookings[max]->getPrice() << " Euro" << endl << endl << endl;

    max = 0;

    for(int i = 0; i < this->rentalCarReservations.size(); i++){
        mietwagenbuchungen_wert += rentalCarReservations[i]->getPrice();
        if(this->rentalCarReservations[i]->getPrice() > this->rentalCarReservations[max]->getPrice()){
            max = i;

        }
    }

    cout << "Teuerste Mietwagenbuchung (ID:" << rentalCarReservations[max]->getId() << "): Vom " << rentalCarReservations[max]->getFromDate() << " bis " << rentalCarReservations[max]->getToDate() << " von " << rentalCarReservations[max]->getPickupLocation() << " nach " << rentalCarReservations[max]->getReturnLocation() << "\nmit " << rentalCarReservations[max]->getCompany() << " zum Preis von " << rentalCarReservations[max]->getPrice() << " Euro" << endl << endl << endl;

    max = 0;

    for(int i = 0; i < this->hotelBookings.size(); i++){
         hotelreservierungen_wert += hotelBookings[i]->getPrice();
        if(this->hotelBookings[i]->getPrice() > this->hotelBookings[max]->getPrice()){
            max = i;

        }
    }

    cout << "Teuerste Hotelbuchung (ID:" << hotelBookings[max]->getId() << "): Vom " << hotelBookings[max]->getFromDate() << " bis " << hotelBookings[max]->getToDate() << " im " << hotelBookings[max]->getHotel() << "\nin " << hotelBookings[max]->getTown() << " zum Preis von " << hotelBookings[max]->getPrice() << "Euro" << endl << endl << endl;

    cout << "Es wurden " << flugbuchungen_anzahl  << " Flugbuchungen im Wert von " << flugbuchungen_wert << " Euro,\n" << mietwagenbuchungen_anzahl << " Mietwagenbuchungen im Wert von " << mietwagenbuchungen_wert << " Euro \nund " << hotelreservierungen_anzahl << " Hotelreservierungen im Wert von " << hotelreservierungen_wert << " Euro angelegt." << endl << endl << endl;


}


