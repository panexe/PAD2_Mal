#include "rentalcarreservation.h"



std::string RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

void RentalCarReservation::setPickupLocation(const std::string &value)
{
    pickupLocation = value;
}

std::string RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

void RentalCarReservation::setReturnLocation(const std::string &value)
{
    returnLocation = value;
}

std::string RentalCarReservation::getCompany() const
{
    return company;
}

void RentalCarReservation::setCompany(const std::string &value)
{
    company = value;
}

std::string RentalCarReservation::getInsuranceType() const
{
    return insuranceType;
}

void RentalCarReservation::setInsuranceType(const std::string &value)
{
    insuranceType = value;
}

std::string RentalCarReservation::showDetails()
{
    return this->insuranceType;
}

RentalCarReservation::RentalCarReservation(long _id, double _price, long _travelID, std::string _fromDate, std::string _toDate, std::string _pickupLocation, std::string _returnLocation, std::string _company, std::string insuranceType_)
    :Booking(_id,_price,_travelID,_fromDate,_toDate),pickupLocation(_pickupLocation),returnLocation(_returnLocation),company(_company), insuranceType(insuranceType_)
{

}
