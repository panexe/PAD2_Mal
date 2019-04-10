#include "rentalcarreservation.h"



RentalCarReservation::RentalCarReservation(long _id, double _price, long _travelID, std::string _fromDate, std::string _toDate, std::string _pickupLocation, std::string _returnLocation, std::string _company)
    :Booking(_id,_price,_travelID,_fromDate,_toDate),pickupLocation(_pickupLocation),returnLocation(_returnLocation),company(_company)
{

}
