#include "travel.h"

Travel::Travel(long _id, long _customerId)
    :id(_id),customerId(_customerId)
{


}

void Travel::addBooking(Booking *booking)
{
    this->travelBookings.push_back(booking);

}
