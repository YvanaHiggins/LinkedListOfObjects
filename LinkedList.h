#ifndef LINKEDLIST_H
#define LINKEDLIST_H
//#pragma once
#include <iostream>
using namespace std;

template <class ItemType>
class LinkedList{


//Overloading the << Operator
friend ostream& operator<<(ostream &out, const LinkedList<ItemType> &ll)
{
  LinkedList<ItemType>::Node* current;
  current = ll.head;
  while(current != NULL)
  {
      out << *(current->data);
      current = current->next;
  }
  return out;
}

public:

  //Constructors
  LinkedList();
  LinkedList(const LinkedList<ItemType>& list1);
  ~LinkedList();

  //Operator overloading
  LinkedList<ItemType> operator+(const LinkedList<ItemType> &list1) const;
  LinkedList<ItemType>& operator+=(const LinkedList<ItemType> &list1);
  LinkedList<ItemType>& operator=(const LinkedList<ItemType> &list1);
  bool operator==(const LinkedList<ItemType> &list1) const;
  bool operator!=(const LinkedList<ItemType> &list1) const;

  //Public LinkedLists methods
  bool Insert(ItemType *obj);
  bool Remove(ItemType target, ItemType &result);
  bool Peek(ItemType target, ItemType &result) const;
  bool isEmpty() const;
  bool Merge(LinkedList<ItemType> &list1);
  void DeleteList();

private:
  //Private node class
  struct Node
  {
    ItemType *data;
    Node *next;
  };

  Node* head;


};

#include "LinkedList.cpp"

#endif
