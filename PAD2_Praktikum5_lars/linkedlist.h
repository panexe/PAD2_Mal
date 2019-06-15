#ifndef LINKEDLLIST_H
#define LINKEDLLIST_H

#endif // LINKEDLLIST_H

#include "node.h"
#include <iostream>


/* For comparison of Template Objects these two template functions are used
 * to account for the template being a pointer ( in this case c++ would
 * compare the memory adress of the pointers)
 *
 * Chooses the the right function and returns a pointer either ways
 * Has some necesarry overhead
 */

template<typename T>
T * ptr(T && obj) { return &obj; } //turn rvalue reference into pointer!

template<typename T>
T * ptr(T & obj) { return &obj; } //turn reference into pointer!

template<typename T>
T * ptr(T * obj) { return obj; } //obj is already pointer, return it!

enum  MODE
{
    SMALLEST_FIRST = 0,
    GREATEST_FIRST
};

/* Implementation of a sorted double linked list
 *
 * For this to work with custom classes the
 * '<' compare operator must be overloaded
 *
 */



template <class T>
class LinkedList
{

    unsigned int count;
    std::shared_ptr<Node<T>> first;
    std::shared_ptr<Node<T>> last;
    std::shared_ptr<Node<T>> cursor;
    MODE mode;


public:

    /*  The list inits empty with the head and tail as nullptrs
     *
     */
    LinkedList(MODE mode_ = MODE::SMALLEST_FIRST)
        : count(0),first(nullptr),last(nullptr), cursor(first), mode(mode_)
    {
        // TODO sfinae !



    }

    /* Returns the value of the node the cursors at
     *
     */
    T get()
    {
        // Error handling :

        if(count == 0)
        {
            throw std::out_of_range("The size of the list is 0. Cant return a value.");
        }

        if(cursor == nullptr)
        {
            throw std::runtime_error("The cursor doesnt point to a node.");
        }

        return cursor->getData();
    }

    /* Returns the value of the n'th element
     *
     * if the value is negative the index is
     * counted from the end of the list
     */
    T get(const int& index)
    {
        // empty list
        if(count == 0)
        {
            throw std::out_of_range("The size of the list is: " + std::to_string(count) + " the given index: "+ std::to_string(index) );
        }

        // calc negative index values
        if(index < 0)
        {
            int newIndex = count + index;
            return get(newIndex);
        }

        if(index > count -1)
        {
            throw std::out_of_range("The size of the list is: " + std::to_string(count) + " the given index: "+ std::to_string(index) );
        }
        // start at the first node and advance to the wanted node

        // start at the head node
        if(index <= (count / 2))
        {
            cursor = first;
            unsigned int i;
            for(i=0; i<index; i++)
            {
                advance();
            }
            return cursor->getData();
        }

        // start at the tail node
        if(index > (count /2))
        {
            cursor = last;
            unsigned int i;
            for(i=0; i< count - index-1; i++)
            {
                advance(-1);
            }
            return cursor->getData();
        }

    }

    /* Removes the object the cursor points to
     *
     */
    void remove()
    {
        // check if the cursor points to an object
        if(cursor == nullptr)
        {
            throw std::runtime_error("The cursor doesnt point to a node.");
        }

        // hanlde empty list
        if(count == 0)
        {
            throw std::runtime_error("Cannot remove an element of an empty list!");
        }

        // make list empty
        if(count == 1)
        {
            clear();
            return;
        }

        // make a one element list
        if(count == 2)
        {
            count--;
            first->setNext(nullptr);
            last->setPrev(nullptr);

            if(cursor == first)
            {
                first = last;
            }else{
                last = first;
            }
            cursor = first;
            return;
        }

        count--;

        // first node code
        if(cursor == first)
        {
            std::shared_ptr<Node<T>> temp = first->getNext();
            temp->setPrev(nullptr);
            first.reset();
            first = temp;
            cursor = first;
            return;
        }

        // last node case
        if(cursor == last)
        {
            std::shared_ptr<Node<T>> temp = last->getPrev();
            temp->setNext(nullptr);
            last.reset();
            last = temp;
            cursor = first;
            return;
        }

        // general case
        std::shared_ptr<Node<T>> tempPrev = cursor->getPrev();
        std::shared_ptr<Node<T>> tempNext = cursor->getNext();
        tempPrev->setNext(tempNext);
        tempNext->setPrev(tempPrev);
        cursor = tempNext;
    }


    /* removes the object at the given index
     *
     */
    void remove(const int& index)
    {
        get(index);
        remove();
    }


    /*  Adds an objects to the list
     *
     */
    void add(const T& value)
    {


        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);

        // Add to an empty list
        if(count == 0)
        {
            count++;
            first = newNode;
            last  = newNode;
            cursor= first;
            return;
        }
        count++;
        // Insert at the head node
        if((mode == SMALLEST_FIRST && *ptr(value) <= *ptr(first->getData())) ||
                (mode == GREATEST_FIRST && *ptr(value) >= *ptr(first->getData())))
        {

            first->setPrev(newNode);
            newNode->setNext(first);
            first = newNode;
            cursor = newNode;
            return;
        }

        // Insert at the tail node
        if((mode == SMALLEST_FIRST && (*ptr(value) >= *ptr(last->getData()))) ||
                (mode == GREATEST_FIRST && (*ptr(value) <= *ptr(last->getData()))))
        {

            last->setNext(newNode);
            newNode->setPrev(last);
            last = newNode;
            cursor = newNode;
            return;
        }

        //-----------------------------------------------------------//
        //                      SMALLEST FIRST                       //
        //-----------------------------------------------------------//
        if(mode == MODE::SMALLEST_FIRST)
        {

            // find the point in the list to add the new element
            cursor = first;
            while(cursor->getNext() != last && *ptr(cursor->getNext()->getData()) < *ptr(value))
            {
                advance();
            }

            // add it inbetween
            std::shared_ptr<Node<T>> temp = cursor->getNext();
            cursor->setNext(newNode);
            temp->setPrev(newNode);
            newNode->setPrev(cursor);
            newNode->setNext(temp);
            return;

        }

        //-----------------------------------------------------------//
        //                      GREATEST FIRST                       //
        //-----------------------------------------------------------//
        if(mode == MODE::GREATEST_FIRST)
        {
            cursor = last;
            while(cursor->getPrev() != first && *ptr(cursor->getPrev()->getData()) < *ptr(value))
            {
                advance(-1);
            }

            std::shared_ptr<Node<T>> temp = cursor->getPrev();
            cursor->setPrev(newNode);
            temp->setNext(newNode);
            newNode->setPrev(temp);
            newNode->setNext(cursor);
            return;

        }

    }

    /*   Moves the cursor the given amount
     *   if the cursor reaches the end it stays there and returns
     *   negative amounts move the opposite direction
     */
    void advance(const int& amount = 1)
    {
        if(amount == 0)
        {
            return;
        }

        // move a positive amount (with check for the end of the list)
        if(amount > 0)
        {
            unsigned int i;
            for (i=0; i<amount; i++)
            {
                if(cursor->getNext() != nullptr)
                {
                    cursor = cursor->getNext();
                }else
                {
                    return;
                }
            }
        }

        // move a positive amount
        if(amount < 0)
        {
            int i;
            for (i=-amount; i>0; i--)
            {
                if(cursor->getPrev() != nullptr)
                {
                    cursor = cursor->getPrev();
                }else
                {
                    return;
                }
            }
        }


    }

    /* sets the cursor to the first node that has the given value
     * if it the list doesnt contain the value it returns FALSE else TRUE
     */
    bool find(const T& value)
    {
        cursor = first;

        while(cursor != last && cursor->getData() != value)
        {
            advance();
        }

        if(last->getData() != value && cursor == last)
        {
            return false;
        }
        return true;

    }


    /*  deletes all elements and resets the counter
     *
     */
    void clear()
    {
        first = nullptr;
        cursor = nullptr;
        last = nullptr;
        count = 0;
    }

    /*  prints the contets of the list to the console
     *  if the list is >10 the first 5 and last 5 are printed
     *  to work with custom classes the ostream'<<' operator must be overloaded
     */
    void print()
    {
        if(count == 0)
        {
            return;
        }


        try
        {

            cursor = first;

            // print the first and last 5 elements
            if(count > 10)
            {
                unsigned int i;
                for (i=0; i<5; i++)
                {
                    std::cout << i << ": " << cursor->getData() << std::endl ;
                    advance();
                }
                advance(count-10);
                std::cout << "..." << std::endl;
                for (i=count-5; i<count; i++)
                {
                    std::cout << i << ": " << cursor->getData() << std::endl;
                    advance();
                }
                return;
            }

            // print all elements
            unsigned int i;
            for (i=0; i<count; i++)
            {
                std::cout << i << ": " << cursor->getData() << std::endl;
                advance();
            }
        }catch(std::exception e)
        {
            std::cout << e.what();
        }
    }

    /*****************************************************************/
    /*                       Getter & Setter                         */
    /*****************************************************************/

    unsigned int Count() const
    {
        return count;
    }
    MODE getMode() const
    {
        return mode;
    }

    /*****************************************************************/
    /*                           Operators                           */
    /*****************************************************************/

    /* Index operator
     *
     */
    T operator[](int index)
    {
        return get(index);
    }

    /* Add a new node to the list
     *
     */
    void operator<<(const T& value)
    {
        add(value);
    }

};
