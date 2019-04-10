#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

#include "travel.h"

class Customer
{
    long id;
    std::string name;
    std::vector<Travel*> travelList;
public:
    Customer(long _id = 0,std::string _name = "");
    void addTravel(Travel* travel);
};

#endif // CUSTOMER_H
