#include "flightbooking.h"

double FlightBooking::getPrice() const
{
    return price;
}

long FlightBooking::getId() const
{
    return id;
}

std::string FlightBooking::getFromDate() const
{
    return fromDate;
}

std::string FlightBooking::getToDate() const
{
    return toDate;
}

std::string FlightBooking::getFromDest() const
{
    return fromDest;
}

std::string FlightBooking::getToDest() const
{
    return toDest;
}

std::string FlightBooking::getAirline() const
{
    return airline;
}

FlightBooking::FlightBooking()
{
    
}

FlightBooking::FlightBooking(long _id, double _price, std::string _fromDate, std::string _toDate, std::string _fromDest, std::string _toDest, std::string _airline)
    : id(_id), price(_price), fromDate(_fromDate), toDate(_toDate),fromDest(_fromDest), toDest(_toDest), airline(_airline)
{

}
