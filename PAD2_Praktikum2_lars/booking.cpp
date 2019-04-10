#include "booking.h"


long Booking::getId() const
{
    return id;
}

void Booking::setId(long value)
{
    id = value;
}

double Booking::getPrice() const
{
    return price;
}

void Booking::setPrice(double value)
{
    price = value;
}

long Booking::getTravelID() const
{
    return travelID;
}

void Booking::setTravelID(long value)
{
    travelID = value;
}

std::string Booking::getFromDate() const
{
    return fromDate;
}

void Booking::setFromDate(const std::string &value)
{
    fromDate = value;
}

std::string Booking::getToDate() const
{
    return toDate;
}

void Booking::setToDate(const std::string &value)
{
    toDate = value;
}

Booking::Booking(long _id, double _price, long _travelID, std::string _fromDate, std::string _toDate):
    id(_id),price(_price),travelID(_travelID),fromDate(_fromDate),toDate(_toDate)
{

}
