#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include <string>

class RentalCarReservation
{
    long id;
    double price;
    std::string toDate;
    std::string fromDate;
    std::string pickupLocation;
    std::string returnLocation;
    std::string company;

public:
    RentalCarReservation(long id,double price,std::string toDate,std::string fromDate,std::string pickupLocation,std::string returnLocation,std::string company);
    RentalCarReservation();
    long getId() const;
    double getPrice() const;
    std::string getToDate() const;
    std::string getFromDate() const;
    std::string getPickupLocation() const;
    std::string getReturnLocation() const;
    std::string getCompany() const;
};

#endif // RENTALCARRESERVATION_H
