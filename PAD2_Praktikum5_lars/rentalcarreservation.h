#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include <string>
#include <vector>

#include "booking.h"

class RentalCarReservation : public Booking
{
    std::string pickupLocation;
    std::string returnLocation;
    std::string company;
    std::string insuranceType;
public:
    RentalCarReservation(long _id = 0, double _price = 0,long _travelID = 0, std::string _fromDate = "", std::string _toDate = "",
                         std::string pickupLocation="",std::string returnLocation="",std::string company="", std::string insuranceType="",std::vector<long> connectedBookings = std::vector<long>());
    std::string getPickupLocation() const;
    void setPickupLocation(const std::string &value);
    std::string getReturnLocation() const;
    void setReturnLocation(const std::string &value);
    std::string getCompany() const;
    void setCompany(const std::string &value);
    std::string getInsuranceType() const;
    void setInsuranceType(const std::string &value);

    std::string showDetails() override;
    std::vector<std::string> getTypeSpecificAtributes() override;

};

#endif // RENTALCARRESERVATION_H
