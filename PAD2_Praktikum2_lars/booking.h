#ifndef BOOKING_H
#define BOOKING_H

#include <string>

class Booking
{
protected:
    long id;
    double price;
    long travelID;
    std::string fromDate;
    std::string toDate;
public:
    Booking(long _id = 0, double _price = 0,long _travelID = 0, std::string _fromDate = "", std::string _toDate = "");
    virtual ~Booking() = default;
    long getId() const;
    void setId(long value);
    double getPrice() const;
    void setPrice(double value);
    long getTravelID() const;
    void setTravelID(long value);
    std::string getFromDate() const;
    void setFromDate(const std::string &value);
    std::string getToDate() const;
    void setToDate(const std::string &value);
};

#endif // BOOKING_H
