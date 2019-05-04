#ifndef TRAVEL_H
#define TRAVEL_H

#include <vector>

#include "booking.h"



class Travel
{
    long id;
    long customerId;
    std::vector<Booking*> travelBookings;

public:
    Travel(long _id = 0, long _customerId = 0);

    void addBooking(Booking* booking);
    long getId() const;
    void setId(long value);
    long getCustomerId() const;
    void setCustomerId(long value);
    long getTravelBookingsSize();
};

#endif // TRAVEL_H
