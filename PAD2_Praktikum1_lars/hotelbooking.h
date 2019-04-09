#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H

#include <string>

class HotelBooking
{
    long id;
    double price;
    std::string fromDate;
    std::string toDate;
    std::string hotel;
    std::string town;


public:
    HotelBooking();
    HotelBooking(long id, double price, std::string fromDate, std::string toDate, std::string hotel, std::string town );
    long getId() const;
    double getPrice() const;
    std::string getFromDate() const;
    std::string getToDate() const;
    std::string getHotel() const;
    std::string getTown() const;
};

#endif // HOTELBOOKING_H
