#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>

template <class T>
class Node{
    private:
        T data;
        Node<T>* prev;
        Node<T>* next;
    public:
        Node();
        //Constructor parametrizado
        Node(const T&);

        T getData() const;
        Node<T>* getNext();
        Node<T>* getPrev();

        void setData(const T&);
        void setNext(Node<T>*);
        void setPrev(Node<T>*);

        std::string toString();
};

template <class T>
Node<T>::Node() : prev(nullptr), next(nullptr)
{

}

template <class T>
Node<T>::Node(const T& e) : data(e), prev(nullptr) ,next(nullptr)
{

}

template <class T>
T Node<T>::getData() const
{
    return data;
}

template <class T>
Node<T>* Node<T>::getPrev()
{
    return prev;
}


template <class T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template <class T>
void Node<T>::setData(const T& e)
{
    data = e;
}

template <class T>
void Node<T>::setPrev(Node<T>*p)
{
    prev = p;
}


template <class T>
void Node<T>::setNext(Node<T>* p)
{
    next = p;
}

template <class T>
std::string Node<T>::toString()
{
    std::string result;

    result = data;

    return result;
}


#endif // NODE_H_INCLUDED
