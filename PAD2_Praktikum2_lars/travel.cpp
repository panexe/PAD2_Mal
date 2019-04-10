#include "travel.h"

long Travel::getId() const
{
    return id;
}

void Travel::setId(long value)
{
    id = value;
}

long Travel::getCustomerId() const
{
    return customerId;
}

void Travel::setCustomerId(long value)
{
    customerId = value;
}

long Travel::getTravelBookingsSize()
{
    return this->travelBookings.size();
}

Travel::Travel(long _id, long _customerId)
    :id(_id),customerId(_customerId)
{


}

void Travel::addBooking(Booking *booking)
{
    // check for duplicates
    for(Booking * b : this->travelBookings){
        if (b->getId() == booking->getId()){
            return;
        }
    }

    this->travelBookings.push_back(booking);

}
