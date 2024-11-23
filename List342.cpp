#include "List342.h"
#include "iostream"
#include <string>

template <class T>
List342<T>::List342() : size_(0), head_(nullptr) {}

template <class T>
bool List342<T>::BuildList(std::string file_name) {



    return true;
}

template <class T>
bool List342<T>::Insert(T* obj) {
    Node<T> *temp = new Node<T>();
    temp->data = obj;
    temp->next = nullptr;

    // If head_ is nullptr
    if(head_ == nullptr) {
        head_ = temp;
        size_++;
        return true;
    }

    Node<T> *index = head_;
    while(index->next != nullptr && index->next->data < temp->data) {
        index = index->next;
    }

    // Do not add if data already exist in list
    if(*index->data == *temp->data) {
        delete temp;
        return false;
    }

    temp->next = index->next;
    index->next = temp;

    size_++;

    return true;
}

template <class T>
bool List342<T>::Remove(T target, T& result) {
    Node<T> *index = head_;
    Node<T> *prev = head_;

    // If head_ is nullptr
    if(head_ == nullptr) {
        return false;
    }

    // Note to self: 
    // Since the list is sorted, we don't have to worry about skipping our target. As soon as we 
    // find a node with a data field that is greater than ours, we know the previous has to be equal
    // or smaller than target.
    while(index->next != nullptr && *index->next->data <= target) { 
        prev = index;
        index = index->next;
    }

    std::cout << *prev->data << std::endl;
    std::cout << *index->data << std::endl;
    std::cout << target << std::endl;
    
    if(*index->data == target) {

        std::cout << "equal" << std::endl;

        prev->next = index->next;
        size_--;
        result = *index->data;
        std::cout << "result: " << result << std::endl;
        delete index;  
        return true;
    }

    return false;
}

template <class T>
bool List342<T>::Peek(T target, T& result) const {



    return true;
}

template <class T>
int List342<T>::Size() const {
    return size_;
}

template <class T>
void List342<T>::DeleteList() {

}

template <class T>
bool List342<T>::Merge(List342& list1) {
    

    return true;
}

template <class T>
List342<T> List342<T>::operator+(const List342& list) const {



    return List342();
}

template <class T>
List342<T>& List342<T>::operator+=(const List342& list) {



    return List342();
}

template <class T>
bool List342<T>::operator==(const List342& list) const {


    return true;
}

template <class T>
bool List342<T>::operator!=(const List342& list) const {


    return true;
}

template <class T>
List342<T>& List342<T>::operator=(const List342& list) {


    return List342();
}

template <class T>
bool List342<T>::contains(T target) const {




    return true;
}

template <class T>
std::string printNext(Node<T> *node) {
    if(node == nullptr) return "";
    // std::cout << *node->data << std::endl;
    return std::to_string(*node->data) + printNext(node->next);
    // return printNext(node->next);
}