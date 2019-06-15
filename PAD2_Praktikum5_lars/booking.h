#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <vector>


class Booking
{
protected:
    long id;
    double price;
    long travelID;
    std::string fromDate;
    std::string toDate;
    char type;

    std::vector<Booking *> connectedBookings;
    std::vector<long> connectedIds;
public:
    Booking(long _id = 0, double _price = 0,long _travelID = 0, std::string _fromDate = "", std::string _toDate = "", char type = ' ',std::vector<long> connectedIds = std::vector<long>());
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

    void addConnectedBooking(Booking* b);

    virtual std::string showDetails() = 0;
    virtual std::vector<std::string> getTypeSpecificAtributes() =0;

    char getType() const;
    void setType(char value);

    /*
    bool operator<(const Booking& other){
        if(this->price < other.price){
            return true;
        }
        return false;
    }
    */
    bool operator<(const Booking& other){
        if(travelID == other.getTravelID()){
            if(fromDate == other.getFromDate()){
                return toDate < other.getToDate();
            }
            return fromDate < other.getFromDate();
        }
        return travelID < other.getTravelID();

    }
    bool operator<=(const Booking& other){
        if(travelID == other.getTravelID()){
            if(fromDate == other.getFromDate()){
                return toDate <= other.getToDate();
            }
            return fromDate <= other.getFromDate();
        }
        return travelID <= other.getTravelID();
    }
    bool operator>(const Booking& other){
        if(travelID == other.getTravelID()){
            if(fromDate == other.getFromDate()){
                return toDate > other.getToDate();
            }
            return fromDate > other.getFromDate();
        }
        return travelID > other.getTravelID();
    }
    bool operator>=(const Booking& other){
        if(travelID == other.getTravelID()){
            if(fromDate == other.getFromDate()){
                return toDate >= other.getToDate();
            }
            return fromDate >= other.getFromDate();
        }
        return travelID >= other.getTravelID();
    }

    std::vector<Booking *> getConnectedBookings() const;
    void setConnectedBookings(const std::vector<Booking *> &value);
    std::vector<long> getConnectedIds() const;
};



#endif // BOOKING_H
