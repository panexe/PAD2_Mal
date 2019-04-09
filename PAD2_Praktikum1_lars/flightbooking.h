#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include <string>

class FlightBooking
{
    long id;
    double price;
    std::string fromDate;
    std::string toDate;
    std::string fromDest;
    std::string toDest;
    std::string airline;

public:
    FlightBooking();
    FlightBooking(long id, double price, std::string fromDate, std::string toDate, std::string fromDest , std::string toDest , std::string airline);
    double getPrice() const;
    long getId() const;
    std::string getFromDate() const;
    std::string getToDate() const;
    std::string getFromDest() const;
    std::string getToDest() const;
    std::string getAirline() const;
};

#endif // FLIGHTBOOKING_H
