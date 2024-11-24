#ifndef LIST342_H
#define LIST342_H
#include <iostream>
#include <string>

template <class T>
struct Node {
  T *data;
  Node *next;
};

template <class T> class List342 {
  public:
    List342();
    List342(const List342& list);

    bool BuildList(std::string file_name);

    bool Insert(T* obj);

    bool Remove(T target, T& result);

    bool Peek(T target, T& result) const;

    int Size() const;
    void DeleteList();
    bool Merge(List342& list1);

    List342 operator+(const List342& list) const;
    List342& operator+=(const List342& list);

    friend std::ostream &operator<<(std::ostream &stream, const List342<T>& list);

    bool operator==(const List342& list) const;
    bool operator!=(const List342& list) const;

    List342<T>& operator=(List342& list);

  friend std::ostream &operator<<(std::ostream &stream, const List342<T>& list) {
    stream << printNext(list.head_);
    return stream;
  }

  private:
    Node<T> *head_;
    int size_;

};
#endif


template <class T>
List342<T>::List342() : size_(0), head_(nullptr) {}

template <class T>
List342<T>::List342(const List342& list) : size_(list.size_) {
    size_ = 0;
    head_ = nullptr;
    Node<T> *index = list.head_;

    while(index != nullptr) {
        Insert(index->data);
        index = index->next;
    }
}

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
    while(index->next != nullptr && *index->next->data < *temp->data) {
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


    if(*index->data == target) {


        prev->next = index->next;
        size_--;
        result = *index->data;

        delete index;  
        return true;
    }

    return false;
}

template <class T>
bool List342<T>::Peek(T target, T& result) const {
    Node<T> *index = head_;

    // If head_ is nullptr
    if(head_ == nullptr) {
        return false;
    }

    // Note to self: 
    // Since the list is sorted, we don't have to worry about skipping our target. As soon as we 
    // find a node with a data field that is greater than ours, we know the previous has to be equal
    // or smaller than target.
    while(index->next != nullptr && *index->next->data <= target) { 
        index = index->next;
    }

    if(*index->data == target) {
        result = *index->data;
        return true;
    }

    return false;
}

template <class T>
int List342<T>::Size() const {
    return size_;
}

template <class T>
void List342<T>::DeleteList() {
    Node<T> *index = head_;

    // If head_ is nullptr
    if(head_ == nullptr) {
        return;
    }

    while(index->next != nullptr) {
        Node<T> *prev = index;
        index = index->next;
        delete prev;
    }

    head_ = nullptr;
    size_ = 0;
    return;
}

template <class T>
bool List342<T>::Merge(List342& list1) {
    Node<T> *p1 = this->head_;
    Node<T> *prev = head_;
    Node<T> *p2 = list1.head_;

    // 1 4 5
    // 2 3 6 7

    // 1 2 4 5
    // 3 6 7
    while(p1 != nullptr && p2 != nullptr) {
        if(*p1->data < *p2->data) { // case 1: index at list 1 is smaller than index at list 2, do nothing and continue
            prev = p1;
            p1 = p1->next;
        } else if(*p1->data > *p2->data) { // case 2: index at list 1 is greater than index at list do, insert element to prev
            prev->next = p2;
            p2 = p2->next;
            prev->next->next = p1;
        } else if (*p1->data == *p2->data) {
            Node<T> *temp = p2;
            p2 = p2->next;
            delete temp;
            temp = NULL;
        } else { // Should never go into here: idiot proofing
            std::cout << "Error in Merge() --> went into else case" << std::endl;
            p1 = p1->next;
        }
    }

    // If we reach the end of p1, we add the remainder of p2 onto the end
    if(p1 == nullptr) {
        prev->next = p2;
        list1.head_ = nullptr;
    }
    
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
List342<T>& List342<T>::operator=(List342& list) {
  DeleteList();
  Node<T> *index = list.head_;

  while(index != nullptr) {
    Insert(index->data);
    index = index->next;
  }

  return *this;
}

template <class T>
std::string printNext(Node<T> *node) {
    if(node == nullptr) return "";
    // std::cout << *node->data << std::endl;
    return std::to_string(*node->data) + printNext(node->next);
    // return printNext(node->next);
}