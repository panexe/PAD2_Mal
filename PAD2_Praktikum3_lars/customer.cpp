#include "customer.h"



long Customer::getId() const
{
    return id;
}

void Customer::setId(long value)
{
    id = value;
}

std::string Customer::getName() const
{
    return name;
}

void Customer::setName(const std::string &value)
{
    name = value;
}

Customer::Customer(long _id, std::string _name):
    id(_id),name(_name)
{

}

void Customer::addTravel(Travel *travel)
{

    if(this->travelList.size() > 0){
        // check for duplicates
        for (Travel * t : this->travelList){
            if(t->getId() == travel->getId()){
                return;
            }
        }
    }


    this->travelList.push_back(travel);

}
