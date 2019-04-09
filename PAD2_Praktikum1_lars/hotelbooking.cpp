#include "hotelbooking.h"

long HotelBooking::getId() const
{
    return id;
}

double HotelBooking::getPrice() const
{
    return price;
}

std::string HotelBooking::getFromDate() const
{
    return fromDate;
}

std::string HotelBooking::getToDate() const
{
    return toDate;
}

std::string HotelBooking::getHotel() const
{
    return hotel;
}

std::string HotelBooking::getTown() const
{
    return town;
}

HotelBooking::HotelBooking()
{
    
}

HotelBooking::HotelBooking(long _id, double _price, std::string _fromDate, std::string _toDate, std::string _hotel, std::string _town)
    : id(_id),price(_price), fromDate(_fromDate), toDate(_toDate), hotel(_hotel), town(_town)
{

}
