#include "flightbooking.h"



std::string FlightBooking::getFromDest() const
{
    return fromDest;
}

void FlightBooking::setFromDest(const std::string &value)
{
    fromDest = value;
}

std::string FlightBooking::getToDest() const
{
    return toDest;
}

void FlightBooking::setToDest(const std::string &value)
{
    toDest = value;
}

std::string FlightBooking::getAirline() const
{
    return airline;
}

void FlightBooking::setAirline(const std::string &value)
{
    airline = value;
}

FlightBooking::FlightBooking(long _id, double _price, long _travelID, std::string _fromDate, std::string _toDate, std::string _fromDest, std::string _toDest, std::string _airline)
    :Booking(_id,_price,_travelID,_fromDate,_toDate), fromDest(_fromDest),toDest(_toDest),airline(_airline)
{

}
