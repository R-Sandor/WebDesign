#ifndef DLLISTUTILS_H
#define DLLISTUTILS_H

#include <cstdlib>  // for NULL


/**
 *  Utility operations for doubly linked lists
 *
 *  Variant: header has first and last pointers
 *
 */




template <typename Data>
struct DListNode
{
  Data data;
  Data cubeNum;
  DListNode<Data>* prev;
  DListNode<Data>* next;

  DListNode() {next = prev = 0;}
  DListNode (const Data& d, DListNode<Data>* prv = 0, DListNode<Data>* nxt = 0)
    : data(d), next(nxt), prev(prv)
  {}
};


template <typename Data>
struct DListHeader {

  DListNode<Data>* first;
  DListNode<Data>* last;

  DListHeader();

  void addToFront (const Data& value);
  void addToEnd (const Data& value);

  // Add value after the indicated position
  void addAfter (DListNode<Data>* afterThis, const Data& value);
  
  // Add value before the indicated position
  void addBefore (DListNode<Data>* beforeThis, const Data& value);

  // Add value in sorted order.
  //Pre: all existing values are already ordered
  void addInOrder (const Data& value);

  // Remove value at the indicated position
  void remove (DListNode<Data>* here);
  
  // Add value after the indicated position
  void removeAfter (DListNode<Data>* afterThis);


  // Search for a value. Returns null if not found
  DListNode<Data>* find (const Data& value) const;

  // Search an ordered list for a value. Returns null if not found
  DListNode<Data>* findOrdered (const Data& value) const;

  // Append another list onto the end of this one
  void append (const DListHeader<Data>& list);

  // Empty the list
  void clear();

};



template <typename Data>
DListHeader<Data>::DListHeader()
  : first(NULL), last(NULL)
{}

template <typename Data>
void DListHeader<Data>::addToFront (const Data& value)
{
  DListNode<Data>* newNode = new DListNode<Data>(value, NULL, first);
  if (first == NULL)
    first = last = newNode;
  else
    {
      first->prev = newNode;
      first = newNode;
    }
}

template <typename Data>
void DListHeader<Data>::addToEnd (const Data& value)
{ 
  DListNode<Data>* newNode = new DListNode<Data>(value, last, NULL);
  if (last == NULL)
    {
      first = last = newNode;
    }
  else
    {
      last->next = newNode;
      last = newNode;
    }
}

// Add value after the indicated position
template <typename Data>
void DListHeader<Data>::addAfter (DListNode<Data>* afterThis, 
				  const Data& value)
{
  DListNode<Data>* newNode
    = new DListNode<Data>(value, afterThis, afterThis->next);
  if (afterThis == last)
    {
      last->next = newNode;
      last = newNode;
    }
  else
    {
      afterThis->next->prev = newNode;
      afterThis->next = newNode;
    }
}
  
  // Add value before the indicated position
template <typename Data>
void DListHeader<Data>::addBefore (DListNode<Data>* beforeThis, 
				   const Data& value)
{
  if (beforeThis == first)
    addToFront (value);
  else
    {
      // Move to front of beforeThis
      DListNode<Data>* current = beforeThis->prev;
      // Link after that node
      addAfter (current, value);
    }
}

// Add value in sorted order.
//Pre: all existing values are already ordered
template <typename Data>
void DListHeader<Data>::addInOrder (const Data& value)
{
  if (first == NULL)
    first = last = new DListNode<Data>(value, NULL, NULL);
  else 
    {
      DListNode<Data>* current = first;
      DListNode<Data>* prev = NULL;
      while (current != NULL && value > current->data)
	{
	  prev = current;
	  current = current->next;
	}
      // Add between prev and current
      if (prev == NULL)
	addToFront (value);
      else
	addAfter (prev, value);
    }
}

// Remove value at the indicated position
template <typename Data>
void DListHeader<Data>::remove (DListNode<Data>* here)
{
  if (here == first)
    {
      DListNode<Data>* after = first->next;
      delete first;
      first = after;
    }
  else
    {
      DListNode<Data>* prev = here->prev;
      prev->next = here->next;
      here->prev = prev;
      if (here == last)
	last = prev;
      delete here;
    }
}


  
  // Add value after the indicated position
template <typename Data>
void DListHeader<Data>::removeAfter (DListNode<Data>* afterThis)
{
  DListNode<Data>* toRemove = afterThis->next;
  afterThis->next = toRemove->next;
  if (afterThis->next != NULL)
    afterThis->next->prev = afterThis;
  if (toRemove == last)
    last = afterThis;
  delete toRemove;
}


  // Search for a value. Returns null if not found
template <typename Data>
DListNode<Data>* DListHeader<Data>::find (const Data& value) const
{
  DListNode<Data>* current = first;
  while (current != NULL && value != current->data)
    current = current->next;
  return current;
}

  // Search an ordered list for a value. Returns null if not found
template <typename Data>
DListNode<Data>* DListHeader<Data>::findOrdered (const Data& value) const
{
  DListNode<Data>* current = first;
  while (current != NULL && value < current->data)
    current = current->next;
  if (current != NULL && value == current->data)
    return current;
  else
    return NULL;
}



// Add all values from another list onto the end of this one
template <typename Data>
void DListHeader<Data>::append (const DListHeader<Data>& list)
{
  // Append new nodes onto end of list
  const DListNode<Data>* current = list.first;
  while (current != NULL)
    {
      DListNode<Data>* newNode = new DListNode<Data>(current->data, last, NULL);
      if (last != NULL)
	  last->next = newNode;
      else
	first = newNode;
      last = newNode;
      current = current->next;
    }
}




template <typename Data>
void DListHeader<Data>::clear()
{
  DListNode<Data>* current = first;
  DListNode<Data>* nxt = NULL;
  while (current != NULL)
    {
      nxt = current->next;
      delete current;
      current = nxt;
    }
  first = last = NULL;
}

#endif
