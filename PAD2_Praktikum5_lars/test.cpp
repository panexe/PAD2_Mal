#include "test.h"
#include "travelagency.h"
#include "rentalcarreservation.h"
#include "flightbooking.h"






void test::Test()
{
    TravelAgency travelAgency;
    travelAgency.readFile();
    int counter_avis = 0;
    int counter_united =0;
    int counter_price =0;

    int i = travelAgency.getBookingsSize() -1;
    for (;i>=0; i--) {
        if(dynamic_cast<RentalCarReservation*>(travelAgency.getBooking(i))){
            RentalCarReservation* rc = dynamic_cast<RentalCarReservation*>(travelAgency.getBooking(i));

            if(rc->getCompany() == "Avis"){
                counter_avis++;
            }
        }else if(dynamic_cast<FlightBooking*>(travelAgency.getBooking(i))){
            FlightBooking *fb = dynamic_cast<FlightBooking*>(travelAgency.getBooking(i));

            if(fb->getAirline() == "United Airlines"){
                counter_united++;
            }

        }
        if(travelAgency.getBooking(i)->getPrice() >= 1000){
            counter_price++;
        }
    }
    QCOMPARE(counter_avis,5);
    QCOMPARE(counter_united,3);
    QCOMPARE(counter_price,31);

}

test::test()
{

}
