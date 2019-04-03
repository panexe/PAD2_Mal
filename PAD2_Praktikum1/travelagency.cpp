#include "travelagency.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ios>


TravelAgency::TravelAgency()
{

}

std::vector<std::string> splitString(std::string in, char seperator){
    std::vector<unsigned int> sep_positions;
    std::vector<std::string> ret;

    // get positions of seperators
    for (unsigned int i = 0; i < in.length(); i++){
        if(in[i] == seperator){
            sep_positions.push_back(i);
        }
    }

    // case theres no seperator in the in-string
    if(sep_positions.size() == 0){
        ret.push_back(in);
        return ret;
    }

    // push substrings into ret-vector
    ret.push_back(in.substr(0,sep_positions[0]));

    for (unsigned int i = 0; i< sep_positions.size(); i++){
        ret.push_back(in.substr(sep_positions[i] +1,sep_positions[i+1] - sep_positions[i] - 1));
    }

    return ret;


}

void TravelAgency::readFile()
{
    std::string filePath = "./bookings.txt";
    std::string line;
    std::ifstream inFile;

    int flight_counter = 0;
    int hotel_counter = 0;
    int car_counter = 0;

    double flight_price = 0;
    double hotel_price = 0;
    double car_price = 0;

    std::vector<std::string> lines;


    // -------- Read File --------------------------

    inFile.open(filePath);
    // check if file can be opened
    if (!inFile){
        std::cout << "Datei konnte nicht geöffnet werden!";
        return;
    }

    // read lines
    while (std::getline(inFile,line)){
        line = line + '\n';
        lines.push_back(line);
    }
    inFile.close();



    /*
    for (unsigned int i = 0; i < lines.size(); i++){
        std::cout << lines[i];
    }
    */


    std::vector<std::vector<std::string>> lines_split;

    for (unsigned int i = 0; i < lines.size(); i++){
        std::vector<std::string> split= splitString(lines[i],'|');
        lines_split.push_back(split);
    }


    // ----------- Process file content------------

    for (unsigned int i = 0; i < lines_split.size(); i++){
        // Flight
        if (lines_split[i][0] == "F"){
            flight_counter++;

            long id = stoi(lines_split[i][1]);
            double price = stoi(lines_split[i][2]);
            std::string fromDate = lines_split[i][3];
            std::string toDate = lines_split[i][4];
            std::string fromDest = lines_split[i][5];
            std::string toDest = lines_split[i][6];
            std::string airline = lines_split[i][7];

            this->flightBookings.push_back(new FlightBooking(id,price,fromDate,toDate,fromDest,toDest,airline));

            flight_price += price;

        }

        else {
            // Car Reservation
            if (lines_split[i][0] == "R"){
                car_counter ++;

                long id = stoi(lines_split[i][1]);
                double price = stoi(lines_split[i][2]);
                std::string fromDate = lines_split[i][3];
                std::string toDate = lines_split[i][4];
                std::string pickupLocation = lines_split[i][5];
                std::string returnLocation = lines_split[i][6];
                std::string company = lines_split[i][7];

                this->rentalCarReservations.push_back(new RentalCarReservation(id,price,fromDate,toDate,pickupLocation,returnLocation,company));

                car_price += price;

            }


            else {
                // Hotel
                if (lines_split[i][0] == "H"){
                    hotel_counter++;

                    long id = stoi(lines_split[i][1]);
                    double price = stoi(lines_split[i][2]);
                    std::string fromDate = lines_split[i][3];
                    std::string toDate = lines_split[i][4];
                    std::string hotel = lines_split[i][5];
                    std::string town = lines_split[i][6];

                    this->hotelBookings.push_back(new HotelBooking(id,price,fromDate,toDate,hotel,town));

                    hotel_price += price;

                }
            }
        }

    }


    // OUTPUT

    std::cout << "Es wurden " << flight_counter << " Fluege im Wert von " << flight_price << " Euro geladen \n";
    std::cout << "Es wurden " << hotel_counter << " Hotels im Wert von " << hotel_price << " Euro geladen \n";
    std::cout << "Es wurden " << car_counter << " Autos im Wert von " << car_price << " Euro geladen \n";



}

struct inputData{

    long id;
    double price;
    std::string airport1;
    std::string airport2;
    std::string business;
    std::string business2;
    std::string city;
    char booking;
    std::string date;
    std::string date2;

    inputData(long _id, double _price, std::string _airport1,std::string _airport2,std::string _business, std::string _business2,std::string _city,char _booking,std::string _date,std::string _date2)
    : id(_id),price(_price), airport1(_airport1),airport2(_airport2), business(_business), business2(_business2),booking(_booking), city(_city),date(_date),date2(_date2)
    {

    }

};


void TravelAgency::readBinaryFile()
{
    // Reads Data from a binary file and puts it into the belonging vectors


    std::string filePath = "./bookingsBinary.bin";
    std::ifstream inFile;
    std::vector<std::string> lines;

    std::vector<inputData> data;

    inFile.open(filePath,std::ios::binary | std::ios::in);

    if(inFile.is_open()){

        // Get the size of the binary file
        int size = 0;
        inFile.seekg(0,std::ios::end);
        size = (int)inFile.tellg();
        inFile.seekg(0,std::ios::beg);


        int t = inFile.tellg();

        while(t < size && t >= 0){

            // input attributes
            long id{0};
            double price{0};
            char airport1[4]{0};
            char airport2[4]{0};
            char business[16]{0};
            char business2[16]{0};
            char city[16]{0};
            char booking{0};
            char date[9]{0};
            char date2[9]{0};

            // ------------- actually read from the file ----------------------------------------
            inFile.read((char*)&booking,sizeof(char));
            if(booking != 'F' && booking != 'R' && booking != 'H'){
                break;
            }
            inFile.read((char*)&id,sizeof(long));
            inFile.read((char*)&price,sizeof(double));
            inFile.read((char*)&date,sizeof(char)*8);
            inFile.read((char*)&date2,sizeof(char)*8);

            // For Flights only
            if(booking == 'F'){
                inFile.read((char*)&airport1,sizeof(char)*3);
                inFile.read((char*)&airport2,sizeof(char)*3);

            }

            inFile.read((char*)&business,sizeof(char)*15);

            // For Hotels only
            if(booking == 'H'){
                inFile.read((char*)&city, sizeof(char)*15);
            }
            // For Car reservations only
            if(booking== 'R'){
                inFile.read((char*)&business2,sizeof(char)*15);
                inFile.read((char*)&city, sizeof(char)*15);

            }

            // save data
            data.push_back(inputData(id,price,airport1,airport2,business, business2,city,booking,date,date2));


            t = inFile.tellg();

        }
        inFile.close();

    }else{
        std::cout << "Cant Open File \n";
    }


    for(unsigned int i = 0; i < data.size(); i++){
        // FLIGHT
        if(data[i].booking == 'F'){
            this->flightBookings.push_back(new FlightBooking(data[i].id,data[i].price,data[i].date,data[i].date2,data[i].airport1,data[i].airport2,data[i].business));


        }else{
            // HOTEL
            if(data[i].booking == 'H'){

                this->hotelBookings.push_back(new HotelBooking(data[i].id,data[i].price,data[i].date,data[i].date2,data[i].business,data[i].city));


            }else{
                // CAR RESERVATION
                if(data[i].booking == 'R'){
                    this->rentalCarReservations.push_back(new RentalCarReservation(data[i].id,data[i].price,data[i].date,data[i].date2,data[i].business,data[i].business2,data[i].city));

                }
            }
        }

    }
    unsigned int highest = 0;

    // Get the index of the most expenive flight
    for (unsigned int i = 0; i < this->flightBookings.size(); i++){
        if(this->flightBookings[i]->getPrice() > this->flightBookings[highest]->getPrice()){
            highest = i;
        }
    }

    std::cout << "Der Teuerste Flug (ID:" << flightBookings[highest]->getId() << ") vom " << flightBookings[highest]->getFromDate() << " bis zum " << flightBookings[highest]->getToDate();
    std::cout << " von " << flightBookings[highest]->getFromDest() << " nach " << flightBookings[highest]->getToDest() << " mit " << flightBookings[highest]->getAirline() << " zum Preis von ";
    std::cout << flightBookings[highest]->getPrice() << std::endl;

    highest = 0;

    // Get the index of the most expenive hotel
    for (unsigned int i = 0; i < this->hotelBookings.size(); i++){
        if(this->hotelBookings[i]->getPrice() > this->hotelBookings[highest]->getPrice()){
            highest = i;
        }
    }

    std::cout << "Das Teuerste Hotel (ID:" << hotelBookings[highest]->getId() << ") vom " << hotelBookings[highest]->getFromDate() << " bis zum " << hotelBookings[highest]->getToDate();
    std::cout << " im " << hotelBookings[highest]->getHotel() << " in " << hotelBookings[highest]->getTown() << " zum Preis von " << hotelBookings[highest]->getPrice() << std::endl;


    highest = 0;

    // Get the index of the most expenive car reservation
    for (unsigned int i = 0; i < this->rentalCarReservations.size(); i++){
        if(this->rentalCarReservations[i]->getPrice() > this->rentalCarReservations[highest]->getPrice()){
            highest = i;
        }
    }

    std::cout << "Der Teuerste Mietwagen (ID:" << rentalCarReservations[highest]->getId() << ") vom " << rentalCarReservations[highest]->getFromDate() << " bis zum " << rentalCarReservations[highest]->getToDate();
    std::cout << " von " << rentalCarReservations[highest]->getPickupLocation() << " nach " << rentalCarReservations[highest]->getReturnLocation() << " mit " << rentalCarReservations[highest]->getCompany() << " zum Preis von " << hotelBookings[highest]->getPrice() << std::endl;





}



