#include "rentalcarreservation.h"

long RentalCarReservation::getId() const
{
    return id;
}

double RentalCarReservation::getPrice() const
{
    return price;
}

std::string RentalCarReservation::getToDate() const
{
    return toDate;
}

std::string RentalCarReservation::getFromDate() const
{
    return fromDate;
}

std::string RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

std::string RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

std::string RentalCarReservation::getCompany() const
{
    return company;
}

RentalCarReservation::RentalCarReservation(long _id, double _price, std::string _toDate, std::string _fromDate, std::string _pickupLocation, std::string _returnLocation, std::string _company)
    :id(_id), price(_price),toDate(_toDate),fromDate(_fromDate),pickupLocation(_pickupLocation),returnLocation(_returnLocation),company(_company)
{

}

RentalCarReservation::RentalCarReservation()
{

}
