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



  private:
    Node<T> *head_;
    int size_;


  friend std::ostream &operator<<(std::ostream &stream, const List342<T>& list) {
    stream << printNext(list.head_);
    return stream;
  }

};



#endif