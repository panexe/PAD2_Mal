#include "customer.h"



Customer::Customer(long _id, std::string _name):
    id(_id),name(_name)
{

}

void Customer::addTravel(Travel *travel)
{
    this->travelList.push_back(travel);

}
