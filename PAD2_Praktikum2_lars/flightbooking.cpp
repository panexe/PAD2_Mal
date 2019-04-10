#include "flightbooking.h"



FlightBooking::FlightBooking(long _id, double _price, long _travelID, std::string _fromDate, std::string _toDate, std::string _fromDest, std::string _toDest, std::string _airline)
    :Booking(_id,_price,_travelID,_fromDate,_toDate), fromDest(_fromDest),toDest(_toDest),airline(_airline)
{

}
