#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include <string>

#include "booking.h"

class FlightBooking : public Booking
{
    std::string fromDest;
    std::string toDest;
    std::string airline;
public:
    FlightBooking(long _id = 0, double _price = 0,long _travelID = 0, std::string _fromDate = "", std::string _toDate = "",
                  std::string _fromDest="",std::string _toDest="",std::string _airline="");
    std::string getFromDest() const;
    void setFromDest(const std::string &value);
    std::string getToDest() const;
    void setToDest(const std::string &value);
    std::string getAirline() const;
    void setAirline(const std::string &value);
};

#endif // FLIGHTBOOKING_H
