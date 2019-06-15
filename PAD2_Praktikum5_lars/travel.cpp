#include "travel.h"
#include "heap.h"
#include <type_traits>
#include "algorithmen.cpp"
#include <flightbooking.h>
#include <deque>
#include "linkedlist.h"

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

int Travel::findIndex(Booking *b)
{
    for (unsigned int i = 0; i<this->travelBookings.size(); i++) {
        if(travelBookings[i]->getId() == b->getId()){
            return int(i+1);
        }
    }
    return -1;
}

Booking *Travel::findBooking(int id)
{
    for (unsigned int i=0; i<travelBookings.size(); i++) {
        if(travelBookings[i]->getId() == id){
            return travelBookings[i];
        }
    }
    return nullptr;
}

bool Travel::checkRoundtrip()
{
    std::deque<Booking*> sortedBookings = makeGraph();


    FlightBooking* firstFlight = nullptr;
    FlightBooking* lastFlight = nullptr;

    for(size_t i = 0; i<travelBookings.size(); i++){
        if(sortedBookings[i]->getType() == 'F'){
            firstFlight = dynamic_cast<FlightBooking*>(sortedBookings[i]);
            i = travelBookings.size();
        }
    }

    for(int i = travelBookings.size()-1; i >= 0; i-- ){
        if(sortedBookings[i]->getType() == 'F'){
            lastFlight = dynamic_cast<FlightBooking*>(sortedBookings[i]);
            i = 0;
        }
    }
    if(firstFlight == nullptr || lastFlight == nullptr){
        std::cerr << "There isnt a flight in this travel";
        return false;
    }

    if(firstFlight == lastFlight){
        std::cerr << "The first is the last flight !";
        return false;
    }

    if(firstFlight->getFromDest() == lastFlight->getToDest()){
        std::cout << "Roundtrip! \n";
        return true;
    }else{
        std::cout << "No rountrip! \n";
        return false;
    }

}

bool Travel::checkMissingHotel()
{

    std::deque<Booking*> sortedBookings = makeGraph();

    if(this->id == 13 || id == 2){
        std::cerr << "hello";
    }

    LinkedList<Booking*> overnightBookings = LinkedList<Booking*>();

    for (int i=0; i<travelBookings.size(); i++) {
        Booking * b = sortedBookings[i];
        if(b->getType() == 'F'){

            if(b->getToDate() > b->getFromDate()){
                overnightBookings.add(b);
            }

        }
        else if(b->getType() == 'H'){
            overnightBookings.add(b);

        }
    }

    if(overnightBookings.Count() < 2){
        return true;
    }

    Booking* a = overnightBookings[-1];
    overnightBookings.remove(-1);
    Booking* b = overnightBookings[-1];
    overnightBookings.remove(-1);

    do{


        if(a->getFromDate() > b->getToDate() ){
            return false;
        }else{

            if(overnightBookings.Count() == 0){
                break;
            }
            a = b;
            b = overnightBookings[-1];
            overnightBookings.remove(-1);
        }

    }while(true);

    return true;



}

bool Travel::checkNeedlessHotel()
{
    std::deque<Booking*> sortedBookings = makeGraph();

    if(this->id == 13 || id == 2){
        std::cerr << "hello";
    }

    LinkedList<Booking*> overnightBookings = LinkedList<Booking*>();

    for (int i=0; i<travelBookings.size(); i++) {
        Booking * b = sortedBookings[i];
        if(b->getType() == 'F'){

            //if(b->getToDate() > b->getFromDate()){
                overnightBookings.add(b);
            //}

        }
        else if(b->getType() == 'H'){
            overnightBookings.add(b);

        }
    }

    if(overnightBookings.Count() < 2){
        return false;
    }

    Booking* a = overnightBookings[-1];
    overnightBookings.remove(-1);
    Booking* b = overnightBookings[-1];
    overnightBookings.remove(-1);

    do{


        if(a->getFromDate() < b->getToDate() ){
            return true;
        }else{

            if(overnightBookings.Count() == 0){
                break;
            }
            a = b;
            b = overnightBookings[-1];
            overnightBookings.remove(-1);
        }

    }while(true);

    return false;


}

bool Travel::checkNeedlessCar()
{
    std::deque<Booking*> sortedBookings = makeGraph();

    if(this->id == 13 || id == 2){
        std::cerr << "hello";
    }

    LinkedList<Booking*> overnightBookings = LinkedList<Booking*>();

    for (int i=0; i<travelBookings.size(); i++) {
        Booking * b = sortedBookings[i];
        if(b->getType() == 'F'){

            //if(b->getToDate() > b->getFromDate()){
                overnightBookings.add(b);
            //}

        }
        else if(b->getType() == 'R'){
            overnightBookings.add(b);

        }
    }

    if(overnightBookings.Count() < 2){
        return false;
    }

    Booking* a = overnightBookings[-1];
    overnightBookings.remove(-1);
    Booking* b = overnightBookings[-1];
    overnightBookings.remove(-1);

    do{


        if(a->getFromDate() < b->getToDate() ){
            return true;
        }else{

            if(overnightBookings.Count() == 0){
                break;
            }
            a = b;
            b = overnightBookings[-1];
            overnightBookings.remove(-1);
        }

    }while(true);

    return false;
}





std::deque<Booking*> Travel::makeGraph()
{

    Graph<Booking*,20 >* graph = new Graph<Booking*,20>;
    node_data sortedArray[travelBookings.size()+1];
    node_data node;

    // add all nodes
    for (unsigned int i = 0; i<this->travelBookings.size(); i++) {
        graph->insertVertex(int(i+1),travelBookings[i]);
    }


    // connect all nodes to each other
    for (unsigned int i = 0; i<this->travelBookings.size(); i++) {
        std::vector<Booking*> connectedBookings = travelBookings[i]->getConnectedBookings();
        for (int j=0; j<connectedBookings.size(); j++) {
            int index = findIndex(connectedBookings[j]);
            graph->insertArc(i+1,index); // changed reinfolge
        }

    }
    DepthFirstSearch(*graph);

    for (int i = 1; i <= travelBookings.size(); i++) {
            sortedArray[i].i = i;
            sortedArray[i].bezeichner = std::to_string(graph->getVertexValue(i)->getId());
            sortedArray[i].end = graph->getEnd(i);
        }

    Heap myHeap(sortedArray,travelBookings.size());


    std::deque<Booking*> sortedBookings;
    for (int i = 1; i <= travelBookings.size(); i++) {
            node = myHeap.pop();
            int id = stoi(node.bezeichner);
            sortedBookings.push_front(findBooking(id));
            cout << i << " " << setw(15) << node.bezeichner << " " << node.end << endl;
        }



    graph->printAdjMatrix();

    return sortedBookings;





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
