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
public:
    TravelAgency();
    ~TravelAgency();
    void readFile();
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);
};

#endif // TRAVELAGENCY_H
