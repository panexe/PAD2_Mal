#include "hotelbooking.h"



std::string HotelBooking::getHotel() const
{
    return hotel;
}

void HotelBooking::setHotel(const std::string &value)
{
    hotel = value;
}

std::string HotelBooking::getTown() const
{
    return town;
}

void HotelBooking::setTown(const std::string &value)
{
    town = value;
}

bool HotelBooking::getSmoke() const
{
    return smoke;
}

void HotelBooking::setSmoke(bool value)
{
    smoke = value;
}

std::string HotelBooking::showDetails()
{
    if(smoke){
        return "Raucher";
    }
    return "Nichtraucher";
}

std::vector<std::string> HotelBooking::getTypeSpecificAtributes()
{
    std::vector<std::string> ret;
    ret.push_back(this->hotel);
    ret.push_back(this->town);
    ret.push_back(this->smoke == true ? "1": "0");

    return ret;
}

HotelBooking::HotelBooking(long _id, double _price, long _travelID, std::string _fromDate, std::string _toDate, std::string _hotel, std::string _town, bool smoke_, std::vector<long> connectedBookings)
    :Booking(_id,_price,_travelID,_fromDate,_toDate,'H', connectedBookings),hotel(_hotel),town(_town), smoke(smoke_)
{

}
