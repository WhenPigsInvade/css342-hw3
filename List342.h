//Harry Fung
//CSS342
//HW3
#ifndef LIST342_H
#define LIST342_H
#include <iostream>
#include <string>
#include <fstream>

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
    Node<T> *index = list.head_;
    while(index != nullptr) {
      stream << *index->data;
      index = index->next;
    }

    // stream << printNext(list.head_);
    return stream;
  }

    bool Contains(T *obj) const;

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
  std::ifstream file;
  file.open(file_name);

  std::string line;

  while (std::getline(file, line)) {
    Insert(new T(line));
  }

  file.close();

  return true;
}

template <class T>
bool List342<T>::Insert(T* obj) {
  if(this->Contains(obj)) {
    return false;
  }

  Node<T> *temp = new Node<T>();
  temp->data = new T(*obj);
  temp->next = nullptr;

  // If head_ is nullptr
  if(head_ == nullptr) {
    head_ = temp;
    size_++;
    return true;
  }

  // 1 3 4
  // 0

  // Insert at front
  if(*head_->data > *temp->data) {
    temp->next = head_;
    head_ = temp;
    size_++;
    return true;
  }

  Node<T>* index = head_;
  while (index->next != nullptr && *index->next->data < *obj) {
      index = index->next;
  }

  // Insert the new node
  temp->next = index->next;
  index->next = temp;


  size_++;

  // std::cout << *this << std::endl;

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

  if(*this == list1) return false;
  if(list1.head_ == nullptr) return false;

  if(head_ == nullptr) {
    head_ = list1.head_;
    list1.head_ = nullptr;
    return true;
  }

  Node<T> *index = list1.head_;

  while(index != nullptr) {
    if(this->Contains(index->data)) {
      Node<T> *temp = index;
      index = index->next;
      delete temp;
      continue;
    }

    if(*head_->data > *index->data) {
      Node<T> *node = index;
      index = index->next;

      node->next = head_;
      head_ = node;

      continue;
    }

    Node<T> *curr = head_;
    while(curr->next != nullptr && *curr->next->data < *index->data) {
      curr = curr->next;
    }

    Node<T> *temp = index->next;
    index->next = curr->next;
    curr->next = index;
    index = temp;

  }

  list1.head_ = nullptr;
  
  return true;
}

template <class T>
List342<T> List342<T>::operator+(const List342& list) const {
  List342 res = *this;
  res += list;
  return res;
}

template <class T>
List342<T>& List342<T>::operator+=(const List342& list) {
  Node<T> *index = list.head_;

  while(index != nullptr) {
    if(!this->Contains(index->data)) {
      this->Insert(index->data);
    }

    index = index->next;
  }
  return *this;
}

template <class T>
bool List342<T>::operator==(const List342& list) const {
  Node<T> *p1 = head_;
  Node<T> *p2 = list.head_;

  if(size_ != list.size_) return false;

  while(p1 != nullptr && p2 != nullptr) {
    if(*p1->data != *p2->data) return false;
    p1 = p1->next;
    p2 = p2->next;
  }

  return true;
}

template <class T>
bool List342<T>::operator!=(const List342& list) const {
  return !(*this==list);
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
bool List342<T>::Contains(T* obj) const {
  bool contains = false;
  Node<T> *index = head_;
  while(index != nullptr && contains == false) {
    if(*index->data == *obj) {
      contains = true;
    }
    index = index->next;
  }
  return contains;
}