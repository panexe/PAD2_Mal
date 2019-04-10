#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H

#include <string>

#include "booking.h"

class HotelBooking : public Booking
{
    std::string hotel;
    std::string town;

public:
    HotelBooking(long _id = 0, double _price = 0,long _travelID = 0, std::string _fromDate = "", std::string _toDate = "",
                 std::string hotel="", std::string town="");
    std::string getHotel() const;
    void setHotel(const std::string &value);
    std::string getTown() const;
    void setTown(const std::string &value);
};

#endif // HOTELBOOKING_H
