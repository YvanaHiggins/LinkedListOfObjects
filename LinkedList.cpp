#include "LinkedList.h"

#include <iostream>
using namespace std;


//LinkedList Constructor
template <class ItemType>
LinkedList<ItemType>::LinkedList()
{
  head = NULL;
}

////////////////////////////////////////////////////////////////////////////////

//LinkedList Destructor
template <class ItemType>
LinkedList<ItemType>::~LinkedList()
{
  DeleteList();
}

////////////////////////////////////////////////////////////////////////////////

//LinkedList Copy Constructor
template <class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& list1)
{
  if (list1.head == NULL)
  {
    head = NULL;
    return;
  }
  else
  {
    head = new LinkedList<ItemType>::Node();
    ItemType *pItemData = new ItemType;
    *pItemData = *(list1.head -> data);
    head -> data = pItemData;
    head -> next = list1.head -> next;
  }

  LinkedList<ItemType>::Node* headNode = head -> next;
  LinkedList<ItemType>::Node* tailNode = head;

  while (headNode != NULL)
  {
    tailNode -> next = new LinkedList<ItemType>::Node();
    tailNode = tailNode -> next;
    tailNode -> data = new ItemType(*(headNode -> data));

    headNode = headNode -> next;
  }

  tailNode -> next = NULL;

}

////////////////////////////////////////////////////////////////////////////////

template <class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+(const LinkedList &list1) const
{
  LinkedList temp = *this;
  temp += list1;
  return temp;
}

////////////////////////////////////////////////////////////////////////////////

template <class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator+=(const LinkedList<ItemType> &list1)
{

  if (list1.head == NULL)
  {
    return *this;
  }

  LinkedList<ItemType>::Node* nodeOther = list1.head;

  if(this->head == NULL)
  {
    LinkedList<ItemType>::Node* temp = new LinkedList<ItemType>::Node();
    ItemType *pItemType = new ItemType;
    *pItemType = *(nodeOther -> data);
    temp -> data = pItemType;
    temp -> next = head;

    head = temp;
  }

  if (*(nodeOther -> data) < *(head -> data))
  {
    LinkedList<ItemType>::Node* temp = new LinkedList<ItemType>::Node();
    ItemType *pItemType = new ItemType;
    *pItemType = *(nodeOther -> data);
    temp -> data = pItemType;
    temp -> next = head;

    head = temp;
    nodeOther = nodeOther -> next;
  }

  LinkedList<ItemType>::Node* nodeThis = head;

  while (nodeOther != NULL)
  {

    if (nodeThis -> next == NULL) //Adds a node to the end of the list
    {
      LinkedList<ItemType>::Node* temp = new LinkedList<ItemType>::Node();
      ItemType *pItemType = new ItemType;
      *pItemType = *(nodeOther -> data);
      temp -> data = pItemType;
      temp -> next = NULL;

      nodeThis -> next = temp;
      nodeOther = nodeOther -> next;
    }
    else if (*(nodeThis-> next -> data) > *(nodeOther -> data)) //Adds to the middle of the list
    {
      LinkedList<ItemType>::Node* temp = new LinkedList<ItemType>::Node();
      ItemType *pItemType = new ItemType;
      *pItemType = *(nodeOther -> data);
      temp -> data = pItemType;
      temp -> next = nodeThis -> next;

      nodeThis-> next = temp;
      nodeOther = nodeOther -> next;

      nodeThis = nodeThis -> next;
    }
    else if(*(nodeThis -> next -> data) == *(nodeOther -> data)) //Skips duplicates
    {
      nodeThis = nodeThis -> next;

      nodeOther = nodeOther -> next;
    }
    else
    {
      nodeThis = nodeThis -> next;
    }

  }

  return *this;
}


////////////////////////////////////////////////////////////////////////////////

//Overloading the == operator
template <class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList<ItemType> &list1) const
{
  if (this -> head == NULL && list1.head == NULL)
  {
    return true;
  }
  else if (this -> head == NULL || list1.head == NULL)
  {
    return false;
  }

  LinkedList<ItemType>::Node* nodeThis = this -> head;
  LinkedList<ItemType>::Node* nodeOther = list1.head;

  while (nodeThis != NULL && nodeOther != NULL)
  {
    if (nodeThis -> next != NULL && nodeOther -> next == NULL)
    {
      return false;
    }
    if (nodeThis -> next != NULL && nodeOther -> next == NULL)
    {
      return false;
    }
    if (*(nodeThis -> data) != *(nodeOther -> data))
    {
      return false;
    }
    nodeThis = nodeThis -> next;
    nodeOther = nodeOther -> next;
  }

  return true;
}

////////////////////////////////////////////////////////////////////////////////

//Overloading the != operator
template <class ItemType>
bool LinkedList<ItemType>::operator!=(const LinkedList<ItemType> &list1) const
{
  if(list1.isEmpty() && this->isEmpty() || (this -> head == NULL && list1.head == NULL))
  {
    return false;
  }

  LinkedList<ItemType>::Node* nodeThis = this -> head;
  LinkedList<ItemType>::Node* nodeOther = list1.head;

  while (nodeThis != NULL || nodeOther != NULL)
  {
    if (nodeThis -> next != NULL && nodeOther -> next == NULL)
    {
      return true;
    }
    if (nodeOther -> next != NULL && nodeThis -> next == NULL)
    {
      return true;
    }
    if (*(nodeThis -> data) != *(nodeOther -> data))
    {
      return true;
    }
    nodeThis = nodeThis -> next;
    nodeOther= nodeOther -> next;
  }

  return true;
}

////////////////////////////////////////////////////////////////////////////////

//Overloading the = operator
template <class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(const LinkedList<ItemType> &list1)
{
  *(this) = list1;
  return true;
}

////////////////////////////////////////////////////////////////////////////////

//Implementing the Insert method
template <class ItemType>
bool LinkedList<ItemType>::Insert(ItemType *obj)
{
  if( (head == NULL) || (*(head->data) > *(obj)) )//If list is empty OR if newNode should go first
  {
    Node* newNode = new Node();
    ItemType *pItemData = new ItemType;
    *pItemData = *obj;
    newNode->data = pItemData;

    newNode->next = head;
    head = newNode;

    return true;
  }
  else
  {
    LinkedList<ItemType>::Node* copy = this->head;

    while(copy != NULL)
    {
      if(*(copy->data) == *obj)
      {
        return false;
      }
      if(copy->next == NULL)
      {
        Node* newNode = new Node();
        ItemType *pItemData = new ItemType;
        *pItemData = *obj;
        newNode->data = pItemData;

        newNode->next = NULL;
        copy->next = newNode;

        return true;
      }
      else if((*(copy->next->data) > *obj) == true)
      {
        Node* newNode = new Node();
        ItemType *pItemData = new ItemType;
        *pItemData = *obj;
        newNode->data = pItemData;

        newNode->next = copy->next;
        copy->next = newNode;
        return true;
      }
      else
      {
        copy = copy->next;
      }

    }

  }
}

////////////////////////////////////////////////////////////////////////////////

//Implement the Remove method
template <class ItemType>
bool LinkedList<ItemType>::Remove(ItemType target, ItemType &result)
{
  if(this->isEmpty() == true)
  {
    return false;
  }

  Node* copy = head;

  if(*(copy->data) == target)
  {
    result = *(copy->data);
    head = head->next;
    delete copy->data;
    delete copy;

    return true;
  }

    while(copy->next != NULL && *(copy->next->data) <= target)
    {
      if (*(copy->next->data) == target)
      {

        result = *(copy->next->data);
        Node* temp = copy->next;
        copy->next = copy->next->next;
        delete temp->data;
        delete temp;

        return true;
      }

      copy = copy->next;
    }


}
////////////////////////////////////////////////////////////////////////////////

//Implementing the Peak method
template <class ItemType>
bool LinkedList<ItemType>::Peek(ItemType target, ItemType &result) const
{
  if(this->isEmpty() == true)
  {
    return false;
  }
    Node* copy = head;
    while(copy != NULL && *(copy->data) <= target)
    {
      if (*(copy->data) == target)
      {
        result = *(copy->data);
        copy = nullptr;
        return true;
      }

      copy = copy->next;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////

//Implementing the isEmpty method
template <class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
  if (head == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}


////////////////////////////////////////////////////////////////////////////////

//Implementing the Merge method
template <class ItemType>
bool LinkedList<ItemType>::Merge(LinkedList<ItemType> &list1)
{
  LinkedList<ItemType>::Node* nodeThis = this->head;
  LinkedList<ItemType>::Node* nodeOther = list1.head;

  if(*(this) == list1)
  {
    return true;
  }

  if (nodeThis == NULL)
  {
    this->head = nodeOther;
    list1.head = NULL;
    nodeOther = NULL;
    return true;
  }

  if (nodeOther == NULL)
  {
    return true;
  }

  Node* tp;

  if (*(nodeThis->data) > *(nodeOther->data))
  {
    tp = nodeOther->next;
    nodeOther->next = nodeThis;
    nodeThis = nodeOther;
    nodeOther = tp;

    this->head = nodeThis;
    list1.head = nodeOther;
 }

  Node* tmp;
  Node* tmp2;
 while(nodeThis->next != NULL)
 {
   if(*(nodeThis->next->data) == *(nodeOther->data))
   {
     tmp = nodeOther;
     nodeOther = nodeOther->next;
     delete tmp->data;
     delete tmp;
   }

   if (*(nodeThis->next->data) > *(nodeOther->data))
   {
     tmp = nodeThis->next;

     tmp2 = nodeOther->next;
     nodeThis->next = nodeOther;
     nodeOther->next = tmp;
     nodeOther = tmp2;
   }
    nodeThis = nodeThis->next;
 }

 nodeThis->next = nodeOther;
 list1.head = NULL;
 return true;
}

////////////////////////////////////////////////////////////////////////////////

//Implementing the DeleteList method
template <class ItemType>
void LinkedList<ItemType>::DeleteList()
{
  if(head == NULL)
  {
    return;
  }

  while(head != nullptr)
  {
    LinkedList<ItemType>::Node* temp = head;
    head = head->next;
    delete temp->data;
    delete temp;
    temp = head;
  }

}
