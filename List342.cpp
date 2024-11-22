#include "List342.h"

template <class T>
List342<T>::List342() : size_(0), head_(nullptr) {}

template <class T>
bool List342<T>::BuildList(std::string file_name) {



    return true;
}

template <class T>
bool List342<T>::Insert(T* obj) {
    Node *temp = new Node();
    temp->data = obj;

    // If head_ is nullptr
    if(head_ == nullptr) {
        head_ = temp;
        return true;
    }

    Node* index = head_;
    while(index->next != nullptr && index->next->data < temp->data) {
        index = index->next;
    }

    // Do not add if data already exist in list
    if(index->next->data == temp->data) {
        return false;
    }

    temp->next = index->next;
    index->next = temp;

    size_++;

    return true;
}

template <class T>
bool List342<T>::Remove(T target, T& result) {





    return true;
}

template <class T>
bool List342<T>::Peek(T target, T& result) const {



    return true;
}

template <class T>
int List342<T>::Size() const {
    return size_;
}

void List342<T>::DeleteList() {

}

bool List342<T>::Merge(List342& list1) {
    

    return true;
}

List342<T> List342<T>::operator+(const List342& list) const {



    return List342();
}

List342& List342::operator+=(const List342& list) {



    return List342();
}

std::istream& operator<<(std::istream& is, List342& list) {



    return is;
}

bool List342::operator==(const List342& list) const {


    return true;
}
bool List342::operator!=(const List342& list) const {


    return true;
}

List342& List342::operator=(const List342& list) {


    return List342();
}



template <class T>
bool List342::contains(T target) const {




    return true;
}
