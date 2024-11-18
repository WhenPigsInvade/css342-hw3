#ifndef LIST342_H
#define LIST342_H
#include <iostream>
#include <string>

template <class T>
struct Node {
  T *data;
  Node *next;
};

class List342 {
  public:
    Node<class T> *head;
    int size;

    bool BuildList(std::string file_name);
    bool Insert(T* obj);
    bool Remove(T target, T& result);
    bool Peek(T target, T& result) const;
    int Size() const;
    void DeleteList();
    bool Merge(List342& list1);

    List342 operator+(const List342& list) const;
    List342& operator+=(const List342& list);

    friend std::istream& operator<<(std::istream& is, List342& list);

    List342 operator==(const List342& list) const;
    List342 operator!=(const List342& list) const;

    List342& operator=(const List342& list);

  private:
    bool contains(T target) const;

};

#endif