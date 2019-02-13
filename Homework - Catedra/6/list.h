#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "node.h"
#include "listexceptions.h"

template <class T> class List {
    private:
        Node<T>* anchor;

        bool isValidPos(Node<T>*);

        void copyAll(const List<T>&);

    public:
        //Definición de la lista
        List();
        List(const List<T>&);
        ~List();

        bool isEmpty();

        void insertData(Node<T>*, const T&); //pos y elemento

        void deleteData (Node<T>*);

        Node<T>* getFirstPos();
        Node<T>* getLastPos ();
        Node<T>* getPrevPos (Node<T>*);
        Node<T>* getNextPos (Node<T>*);

        Node<T>* findDAtaL(const T&);

        T retrieve(Node<T>*); //recupera un elemento

        void deleteAll();

        std::string toString();

        List<T>& operator = (const List<T>&);

        //void writeToDisk(const string&);
        //void readFromDisk(const string&);

};

template <class T>
bool List<T>::isValidPos(Node<T>* p) {
    Node<T>* aux(anchor);

    while(aux != nullptr){
        if(aux == p){
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

template <class T> //Cambiar
void List<T>::copyAll(const List<T>& l) {
    Node<T>* aux(l.anchor);
    Node<T>* lastInserted(nullptr);
    Node<T>* newNode;

    while(aux != nullptr){
        newNode = new Node<T>(aux->getData());

        if(newNode == nullptr){
            throw ListException("\nMemoria no disponible, copyAll\n");
        }

        if(lastInserted == nullptr){
            anchor = newNode;
        }
        else{
            lastInserted->setNext(newNode);
            newNode->setPrev(lastInserted);
        }
        lastInserted = newNode;
        aux = aux->getNext();
    }
}

template <class T>
List<T>::List(): anchor(nullptr) {

}

template <class T>
List<T>::List(const List<T>& l): anchor(nullptr) {
    copyAll(l);
}

template <class T>
List<T>::~List() {
    deleteAll();
}

template <class T>
bool List<T>::isEmpty() {
    return anchor == nullptr;
}

template <class T>
void List<T>::insertData(Node<T>* p, const T& e) {
    if(p != nullptr and !isValidPos(p)) {
        throw ListException("\nPosicion invalida, insertData\n");
    }

    Node<T>* aux(new Node<T>(e));

    if(aux == nullptr) {
        throw ListException("\nMemoria no disponible, insertData\n");
    }

    if(p == nullptr) { //Insertar al principio
        aux->setNext(anchor);
        if(anchor != nullptr){
            anchor->setPrev(aux);
        }
        anchor = aux;
    }
    else { //Insertar en cualquier otra posicion
        aux->setPrev(p);
        aux->setNext(p->getNext());

        if(p->getNext() != nullptr){
            p->getNext()->setPrev(aux);
        }
        p->setNext(aux);
    }
}

template <class T>
void List<T>::deleteData(Node<T>* p) {
    if(!isValidPos(p)) {
        throw ListException("\nPosicion invalida, deleteData\n");
    }

    if(p->getPrev() != nullptr){
        p->getPrev()->setNext(p->getNext());
    }

    if(p->getNext() != nullptr){
        p->getNext()->setPrev(p->getPrev());
    }

    if(p == anchor){
        anchor = anchor->getNext();
    }

    delete p;
}

template <class T>
Node<T>* List<T>::getFirstPos() {
    return anchor;
}

template <class T>
Node<T>* List<T>::getLastPos() {
    if(isEmpty()) {
        return nullptr;
    }

    Node<T>* aux(anchor);

    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
    }

    return aux;
}

template <class T>
Node<T>* List<T>::getPrevPos(Node<T>* p) {
    if(!isValidPos(p)){
        return nullptr;
    }

    return p->getPrev();
}

template <class T>
Node<T>* List<T>::getNextPos(Node<T>* p) {
    if(!isValidPos(p)) {
        return nullptr;
    }

    return p->getNext();
}

template <class T>
Node<T>* List<T>::findDAtaL(const T& e) {
    Node<T>* aux(anchor);

    while(aux != nullptr and aux->getData() != e) {
        aux = aux->getNext();
    }

    return aux;
}

template <class T>
T List<T>::retrieve(Node<T>* p) {
    if(!isValidPos(p)) {
        throw ListException("\nPosicion invalida, retrieve\n");
    }

    return p->getData();
}

template <class T>
void List<T>::deleteAll() {

    Node<T>* aux;

    while(anchor != nullptr){
        aux = anchor;
        anchor = anchor->getNext();

        delete aux;
    }
}

template <class T>
std::string List<T>::toString() {
    std::string result;

    Node<T>* aux(anchor);

    while(aux != nullptr){
        result += aux->getData().toString() + "\n";
        aux = aux->getNext();
    }

    return result;

}

template <class T>
List<T>& List<T>::operator=(const List<T>& l) {
    deleteAll();
    copyAll(l);

    return *this;
}



#endif // LIST_H_INCLUDED
