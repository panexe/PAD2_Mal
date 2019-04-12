#include "travelagency.h"
#include <fstream>
#include <iostream>

#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"

int TravelAgency::getHighestId()
{
    // return the id with the highest numeric values in allBookings
    int ret = 0;

    for (Booking *b : this->allBookings){
        if (b->getId() > ret){
            ret = b->getId();
        }
    }

    return ret;
}

TravelAgency::TravelAgency()
{

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
    for(Travel* t :  allTravels){
        delete t;
    }
    allTravels.clear();

    for(Customer* c : allCustomers){
        delete  c;
    }
    allCustomers.clear();

    for(Booking* b : allBookings){
        delete b;
    }
    allBookings.clear();

}


void TravelAgency::readFile()
{
    std::string filePath = "./bookings2.txt";

    std::ifstream file;

    file.open(filePath);

    // check if file opened
    if(!file.is_open()){
        std::cout << "Datei konnte nicht geoeffnet werden \n";
        return;
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


    for (unsigned int i = 0; i < lines_split.size(); i++){
        // ----------------------- Flight Objects ---------------------------------------------------------------
        //---------------------------------------------------------------------------------------------------

        if (lines_split[i][0][0] == 'F'){


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

                numF++;
                price_sum += price;

                FlightBooking * booking = new FlightBooking(id,price,travelId,fromDate,toDate,fromDest,toDest,airline);
                this->allBookings.push_back(booking);




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

                    numH++;
                    price_sum += price;

                    HotelBooking * booking = new HotelBooking(id,price,travelId,fromDate,toDate,hotel,town);
                    this->allBookings.push_back(booking);




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

                        numC++;
                        price_sum += price;

                        RentalCarReservation* booking = new RentalCarReservation(id,price,travelId,fromDate,toDate,pickupLocation,returnLocation,company);
                        this->allBookings.push_back(booking);




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


    //------------------------- Output --------------------------------

    int numCustomer1{0};
    int numTravel17{0};

    for( Travel * t : allTravels){
        if (t->getCustomerId() == 1){
            numCustomer1++;
        }
    }

    numTravel17 = findTravel(17)->getTravelBookingsSize();



    std::cout << "Es wurden " << numF << " Fluege, " << numH << " Hotels, und " << numC << " Autos im Wert von " << price_sum << " Euro gebucht \n";
    std::cout << "Es wurden " << allCustomers.size() << " Kunden und " << allTravels.size() << " Reisen angelegt \n";
    std::cout << "Der Kunde mit der ID 1 hat " << numCustomer1 << " Reisen gebucht. \n";
    std::cout << "Die Reise mit der ID 17 hat " << numTravel17 << " Buchungen \n";





}

Booking *TravelAgency::findBooking(long id)
{
    // input :: id(long) - the id of the booking object
    // searches a Booking pointer
    // if it exists it returns it, else it returns a nullptr

    for (Booking* b : this->allBookings){
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



int TravelAgency::createBooking(char type, double price, std::string start, std::string end, long travelID, std::vector<std::string> bookingDetails)
{
    if (findTravel(travelID) == nullptr){
        return -1;
    }

    long newId = this->getHighestId() +1;

    if (type == 'F'){
        allBookings.push_back(new FlightBooking(newId,price,travelID,start,end,bookingDetails[0],bookingDetails[1],bookingDetails[2]));
        this->findTravel(travelID)->addBooking(allBookings[allBookings.size()-1]);

    }else {
        if(type == 'H'){
            allBookings.push_back(new HotelBooking(newId,price,travelID,start,end,bookingDetails[0],bookingDetails[1]));
            this->findTravel(travelID)->addBooking(allBookings[allBookings.size()-1]);

        }else{
            if (type == 'R'){
                allBookings.push_back(new RentalCarReservation(newId,price,travelID,start,end,bookingDetails[0],bookingDetails[1],bookingDetails[2]));
                this->findTravel(travelID)->addBooking(allBookings[allBookings.size()-1]);

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

    for (Booking *b : allBookings){
        // Flight
        if(FlightBooking *f = dynamic_cast<FlightBooking*>(b)) {

            numF++;
            price += f->getPrice();
        }else{
            // Hotel
            if(HotelBooking *h = dynamic_cast<HotelBooking*>(b)) {
               // old was safely casted to NewType
                numH++;
                price += h->getPrice();

            }else{
                // car
                if(RentalCarReservation *r = dynamic_cast<RentalCarReservation*>(b)) {
                   // old was safely casted to NewType
                    numR++;
                    price += r->getPrice();

                }
            }
        }
    }

    // OUTPUT

    std::cout << "Es wurden " << numF << " Fluege, " << numH << " Hotels, und " << numR << " Autos im Wert von " << price << " Euro gebucht \n";


}
