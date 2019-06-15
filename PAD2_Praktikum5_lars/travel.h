#ifndef TRAVEL_H
#define TRAVEL_H

#include <vector>

#include "booking.h"
#include "graph.h"
#include <deque>



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

    int findIndex(Booking* b);
    Booking* findBooking(int index);

    bool checkRoundtrip();
    bool checkMissingHotel();
    bool checkNeedlessHotel();
    bool checkNeedlessCar();

    std::deque<Booking*> makeGraph();
};

#endif // TRAVEL_H
