#include "travelagency.h"
#include <fstream>
#include <iostream>
#include <string>

#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"

#include <QMessageBox>


int TravelAgency::getHighestId()
{

    // return the id with the highest numeric values in allBookings
    int ret = 0;

    for (int i = 0; i<allBookings.Count(); i++){
        Booking * b = allBookings[i];
        if (b->getId() > ret){
            ret = b->getId();
        }
    }

    return ret;
}

TravelAgency::TravelAgency()
{
    std::cerr << this->allBookings.Count();

}

std::vector<std::string> splitString(std::string in, char seperator){
    // Splits a string into substring devided by a sperator
    // input : string:in (the string that gets split)
    // input : char:seperator (the char that seperates the substrings)
    // return : vector<string> (the segments)


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

TravelAgency::~TravelAgency()
{
    for(unsigned int i = 0; i<allTravels.size(); i++){
        delete allTravels[i];
    }
    allTravels.clear();

    for(unsigned int i =0; i<allCustomers.size(); i++){
        delete  allCustomers[i];
    }
    allCustomers.clear();

    for(int i = 0; i<allBookings.Count(); i++){
        delete allBookings[i];
    }
    allBookings.clear();

}


std::string TravelAgency::readFile()
{
    std::string filePath = "./bookings_praktikum5.txt";

    std::ifstream file;

    file.open(filePath);

    // check if file opened
    if(!file.is_open()){
        return "Datei konnte nicht geoeffnet werden \n";

    }

    // read all text in the file
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file,line)){
        line = line + '\n';
        lines.push_back(line);
    }
    file.close();


    // split the text from the file into segments
    std::vector<std::vector<std::string>> lines_split;

    for (unsigned int i = 0; i < lines.size(); i++){
        std::vector<std::string> split= splitString(lines[i],'|');
        lines_split.push_back(split);
    }

    int numF{0},numH{0},numC{0};
    double price_sum{0};
    unsigned int i;

    try {


        for (i = 0; i < lines_split.size(); i++){
            // ----------------------- Flight Objects ---------------------------------------------------------------
            //---------------------------------------------------------------------------------------------------

            if (lines_split[i][0][0] == 'F'){

                if(lines_split.size() >=12 && lines_split.size() <= 14){
                    throw std::runtime_error("Invalid amount of arguments!");
                }

                long id = std::stol(lines_split[i][1]);

                // check for duplicates
                if (this->findBooking(id) == nullptr){
                    double price = std::stod(lines_split[i][2]);
                    std::string fromDate = lines_split[i][3];
                    std::string toDate = lines_split[i][4];
                    long travelId = std::stol(lines_split[i][5]);
                    long customerId = std::stol(lines_split[i][6]);
                    std::string customerName = lines_split[i][7];
                    std::string fromDest = lines_split[i][8];
                    std::string toDest = lines_split[i][9];
                    std::string airline = lines_split[i][10];
                    char seatPref = lines_split[i][11][0];
                    std::vector<long> connectedBookings;
                    if(lines_split[i].size() == 13){
                        connectedBookings.push_back(stol(lines_split[i][12]));
                    }
                    if(lines_split[i].size() == 14){
                        connectedBookings.push_back(stol(lines_split[i][13]));
                    }


                    numF++;
                    price_sum += price;

                    FlightBooking * booking = new FlightBooking(id,price,travelId,fromDate,toDate,fromDest,toDest,airline,seatPref,connectedBookings);
                    this->allBookings.add(booking);




                    if (this->findCustomer(customerId) == nullptr){
                        // TODO add new customer
                        this->allCustomers.push_back(new Customer(customerId,customerName));
                    }

                    if (this->findTravel(travelId) == nullptr){
                        // TODO add new travel
                        this->allTravels.push_back(new Travel(travelId,customerId));
                    }

                    findCustomer(customerId)->addTravel(findTravel(travelId));
                    findTravel(travelId)->addBooking(booking);


                }

            }else{
                //-------------------------- Hotel Objects ----------------------------------------------------------
                //---------------------------------------------------------------------------------------------------
                if (lines_split[i][0][0] == 'H'){

                    if(lines_split.size() >=11 && lines_split.size() <= 13){
                        throw std::runtime_error("Invalid amount of arguments!");
                    }

                    long id = std::stol(lines_split[i][1]);

                    // check for duplicates
                    if (this->findBooking(id) == nullptr){
                        double price = std::stod(lines_split[i][2]);
                        std::string fromDate = lines_split[i][3];
                        std::string toDate = lines_split[i][4];
                        long travelId = std::stol(lines_split[i][5]);
                        long customerId = std::stol(lines_split[i][6]);
                        std::string customerName = lines_split[i][7];
                        std::string hotel = lines_split[i][8];
                        std::string town = lines_split[i][9];
                        bool smoke = lines_split[i][10][0] == '0' ? 0 : 1;
                        std::vector<long> connectedBookings;
                        if(lines_split[i].size() == 12){
                            connectedBookings.push_back(stol(lines_split[i][11]));
                        }
                        if(lines_split[i].size() == 13){
                            connectedBookings.push_back(stol(lines_split[i][12]));
                        }


                        numH++;
                        price_sum += price;

                        HotelBooking * booking = new HotelBooking(id,price,travelId,fromDate,toDate,hotel,town,smoke,connectedBookings);
                        this->allBookings.add(booking);




                        if (this->findCustomer(customerId) == nullptr){
                            // TODO add new customer
                            this->allCustomers.push_back(new Customer(customerId,customerName));
                        }

                        if (this->findTravel(travelId) == nullptr){
                            // TODO add new travel
                            this->allTravels.push_back(new Travel(travelId,customerId));
                        }

                        findCustomer(customerId)->addTravel(findTravel(travelId));
                        findTravel(travelId)->addBooking(booking);


                    }



                }else{
                    // -------------------------Car Reservation Objects ---------------------------------------------
                    //---------------------------------------------------------------------------------------------------

                    if(lines_split[i][0][0] == 'R'){

                        if(lines_split.size() >=12 && lines_split.size() <= 14){
                            throw std::runtime_error("Invalid amount of arguments!");
                        }

                        long id = std::stol(lines_split[i][1]);

                        // check for duplicates
                        if (this->findBooking(id) == nullptr){
                            double price = std::stod(lines_split[i][2]);
                            std::string fromDate = lines_split[i][3];
                            std::string toDate = lines_split[i][4];
                            long travelId = std::stol(lines_split[i][5]);
                            long customerId = std::stol(lines_split[i][6]);
                            std::string customerName = lines_split[i][7];
                            std::string pickupLocation = lines_split[i][8];
                            std::string returnLocation = lines_split[i][9];
                            std::string company = lines_split[i][10];
                            std::string insuranceType = lines_split[i][11];
                            std::vector<long> connectedBookings;
                            if(lines_split[i].size() == 13){
                                connectedBookings.push_back(stol(lines_split[i][12]));
                            }
                            if(lines_split[i].size() == 14){
                                connectedBookings.push_back(stol(lines_split[i][13]));
                            }
                            numC++;
                            price_sum += price;

                            RentalCarReservation* booking = new RentalCarReservation(id,price,travelId,fromDate,toDate,pickupLocation,returnLocation,company, insuranceType, connectedBookings);
                            this->allBookings.add(booking);




                            if (this->findCustomer(customerId) == nullptr){
                                // TODO add new customer
                                this->allCustomers.push_back(new Customer(customerId,customerName));
                            }

                            if (this->findTravel(travelId) == nullptr){
                                // TODO add new travel
                                this->allTravels.push_back(new Travel(travelId,customerId));
                            }

                            findCustomer(customerId)->addTravel(findTravel(travelId));
                            findTravel(travelId)->addBooking(booking);


                        }


                    }
                }
            }


        }
    } catch (std::exception read_error) {

        QMessageBox::warning(nullptr,"Fehler beim Datei Einlesen!","Es liegt ein Fehler in Zeile "+QString::number(i+1)+ " vor");
        this->allBookings.clear();
        return "Fehlerhates einlesen";
    }


    //------------------------- Output --------------------------------


    idsToBookings();

    int numCustomer1{0};
    int numTravel17{0};

    for( Travel * t : allTravels){
        if (t->getCustomerId() == 1){
            numCustomer1++;
        }

    }

    numTravel17 = findTravel(17)->getTravelBookingsSize();
    std::string numF_string = std::to_string(numF);
    std::string numH_string = std::to_string(numH);
    std::string numC_string = std::to_string(numC);
    std::string price_sum_string = std::to_string(price_sum);



    std::string ret = "";
    ret += "Es wurden " + numF_string + " Fluege, " + numH_string + " Hotels, und " + numC_string + " Autos im Wert von " + price_sum_string + " Euro gebucht \n";
    return ret;
    std::cout << "Es wurden " << allCustomers.size() << " Kunden und " << allTravels.size() << " Reisen angelegt \n";
    std::cout << "Der Kunde mit der ID 1 hat " << numCustomer1 << " Reisen gebucht. \n";
    std::cout << "Die Reise mit der ID 17 hat " << numTravel17 << " Buchungen \n";





}

std::string TravelAgency::toFileString()
{
    std::string ret = "";
    unsigned int i;
    for (i=0; i<this->allBookings.Count(); i++) {
        Booking *b = allBookings[i];


        std::vector<std::string> attributes = b->getTypeSpecificAtributes();
        std::string temp = "";
        temp.push_back(b->getType());
        temp.push_back('|');
        temp.append(std::to_string(b->getId()));
        temp.push_back('|');
        temp.append(std::to_string(b->getPrice()));
        temp.push_back('|');
        temp.append(b->getFromDate());
        temp.push_back('|');
        temp.append(b->getToDate());
        temp.push_back('|');
        temp.append(std::to_string(b->getTravelID()));
        temp.push_back('|');
        temp.append(std::to_string(this->findTravel(b->getTravelID())->getCustomerId()));
        temp.push_back('|');
        temp.append(this->findCustomer(this->findTravel(b->getTravelID())->getCustomerId())->getName());

        for (unsigned int i= 0; i< attributes.size(); i++) {
            temp.push_back('|');
            temp.append(attributes[i]);
        }
        ret.append(temp);
        ret.push_back('\n');





    }
    return ret;
}

Booking *TravelAgency::findBooking(long id)
{
    // input :: id(long) - the id of the booking object
    // searches a Booking pointer
    // if it exists it returns it, else it returns a nullptr

    unsigned int i;
    for (i=0; i<allBookings.Count(); i++){
        Booking * b =allBookings[i];
        if(b->getId() == id){
            return b;
        }
    }
    return nullptr;
}

Travel *TravelAgency::findTravel(long id)
{
    // input :: id(long) - the id of the travel object
    // searches a Travel pointer
    // if it exists it returns it, else it returns a nullptr

    for (Travel* t : this->allTravels){
        if(t->getId() == id){
            return t;
        }
    }
    return nullptr;
}

Customer *TravelAgency::findCustomer(long id)
{
    // input :: id(long) - the id of the customer object
    // searches a Customer pointer
    // if it exists it returns it, else it returns a nullptr

    for (Customer* c : this->allCustomers){
        if(c->getId() == id){
            return c;
        }
    }
    return nullptr;
}

Booking *TravelAgency::getBooking(unsigned int index)
{
    if(index > this->allBookings.Count()){
        return nullptr;
    }
    return this->allBookings[int(index)];
}

int TravelAgency::getBookingsSize()
{
    int a = this->allBookings.Count();
    return a;
}

Travel *TravelAgency::getTravel(unsigned int index)
{
    if(index > this->allTravels.size()){
        return nullptr;
    }
    return this->allTravels[int(index)];
}

int TravelAgency::getTravelSize()
{
    return allTravels.size();
}

void TravelAgency::idsToBookings()
{
    unsigned int i;
    for (i=0; i<allBookings.Count(); i++) {
        std::vector<long> cB = allBookings[i]->getConnectedIds();
        for(auto l : cB){
            allBookings[i]->addConnectedBooking(findBooking(l));
        }
    }
}



int TravelAgency::createBooking(char type, double price, std::string start, std::string end, long travelID, std::vector<std::string> bookingDetails)
{
    if (findTravel(travelID) == nullptr){
        return -1;
    }

    long newId = this->getHighestId() +1;

    if (type == 'F'){
        allBookings.add(new FlightBooking(newId,price,travelID,start,end,bookingDetails[0],bookingDetails[1],bookingDetails[2],bookingDetails[3][0]));
        this->findTravel(travelID)->addBooking(allBookings[allBookings.Count()-1]);

    }else {
        if(type == 'H'){
            allBookings.add(new HotelBooking(newId,price,travelID,start,end,bookingDetails[0],bookingDetails[1],bookingDetails[2] == "1" ? true :false ));
            this->findTravel(travelID)->addBooking(allBookings[allBookings.Count()-1]);

        }else{
            if (type == 'R'){
                allBookings.add(new RentalCarReservation(newId,price,travelID,start,end,bookingDetails[0],bookingDetails[1],bookingDetails[2],bookingDetails[3]));
                this->findTravel(travelID)->addBooking(allBookings[allBookings.Count()-1]);

            }
        }
    }

    return newId;

}

void TravelAgency::printNumerals()
{
    // prints the sum of each objekt type in all bookings and the sum of all prices

    int numF{0},numH{0}, numR{0};
    double price{0};

    unsigned int i;
    for (i=0; i<allBookings.Count(); i++){
        Booking* b = allBookings[i];
        // Flight
        if(b->getType() == 'F') {

            numF++;
            price += b->getPrice();
        }else{
            // Hotel
            if(b->getType() == 'H') {
                // old was safely casted to NewType
                numH++;
                price += b->getPrice();

            }else{
                // car
                if(b->getType() == 'R') {
                    // old was safely casted to NewType
                    numR++;
                    price += b->getPrice();

                }
            }
        }
    }

    // OUTPUT

    std::cout << "Es wurden " << numF << " Fluege, " << numH << " Hotels, und " << numR << " Autos im Wert von " << price << " Euro gebucht \n";


}
