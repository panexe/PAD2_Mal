#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include "rentalcarreservation.h"
#include "hotelbooking.h"
#include "flightbooking.h"

#include <vector>

class TravelAgency
{
   std::vector<RentalCarReservation*> rentalCarReservations;
   std::vector<HotelBooking*> hotelBookings;
   std::vector<FlightBooking*> flightBookings;



public:
    TravelAgency();
    void readFile();
    void readBinaryFile();
};

#endif // TRAVELAGENCY_H
