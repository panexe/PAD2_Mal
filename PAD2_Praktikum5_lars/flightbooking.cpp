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

char FlightBooking::getSeatPref() const
{
    return seatPref;
}

void FlightBooking::setSeatPref(char value)
{
    seatPref = value;
}

std::string FlightBooking::showDetails()
{
    if(this->seatPref == 'A'){
        return "Gang";
    }
    if(this->seatPref == 'W'){
        return "Fenster";
    }
    return "ERROR in FLIGHTBOOKING with ID: " + std::to_string(this->id);
}

std::vector<std::string> FlightBooking::getTypeSpecificAtributes()
{
    std::vector<std::string> ret;
    ret.push_back(this->fromDest);
    ret.push_back(this->toDest);
    ret.push_back(this->airline);
    ret.push_back(std::to_string(this->seatPref));
    return ret;
}

FlightBooking::FlightBooking(long _id, double _price, long _travelID, std::string _fromDate, std::string _toDate, std::string _fromDest, std::string _toDest, std::string _airline, char seatPref_,std::vector<long> _connectedBooking)
    :Booking(_id,_price,_travelID,_fromDate,_toDate,'F',_connectedBooking), fromDest(_fromDest),toDest(_toDest),airline(_airline),seatPref(seatPref_)
{

}
