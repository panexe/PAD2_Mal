#ifndef NODE_H
#define NODE_H

#endif // NODE_H

#include <memory>

template <class T>
class Node{

    T data;
    std::shared_ptr<Node<T>> prev;
    std::shared_ptr<Node<T>> next;

public:
    Node(T data_ , std::shared_ptr<Node<T>> prev_ = nullptr,std::shared_ptr<Node<T>> next_=nullptr)
        : data(data_),prev(prev_),next(next_)
    {

    }

    /*****************************************************************/
    /*                       Getter & Setter                         */
    /*****************************************************************/

    T getData() const{
        return data;
    }
    void setData(const T &value){
        data = value;
    }
    std::shared_ptr<Node<T> > getPrev() const{
        return prev;
    }
    void setPrev(const std::shared_ptr<Node<T> > &value){
        prev = value;
    }
    std::shared_ptr<Node<T> > getNext() const{
        return next;
    }
    void setNext(const std::shared_ptr<Node<T> > &value){
        next = value;
    }
};
