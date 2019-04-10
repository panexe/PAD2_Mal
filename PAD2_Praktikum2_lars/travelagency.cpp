#include "travelagency.h"

TravelAgency::TravelAgency()
{

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
