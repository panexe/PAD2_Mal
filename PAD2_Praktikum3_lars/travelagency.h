#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <vector>

#include "booking.h"
#include "travel.h"
#include "customer.h"

class TravelAgency
{
    std::vector<Booking*> allBookings;
    std::vector<Travel*> allTravels;
    std::vector<Customer*> allCustomers;

    int getHighestId();
public:
    TravelAgency();
    ~TravelAgency();
    std::string readFile();
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);

    Booking *getBooking(unsigned int index);
    int getBookingsSize();

    int createBooking(char type, double price, std::string start, std::string end, long travelID, std::vector<std::string> bookingDetails);
    void printNumerals();

};


#endif // TRAVELAGENCY_H
