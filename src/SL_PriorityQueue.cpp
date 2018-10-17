#include "SL_PriorityQueue.h"
#include <iostream>


template<class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue()
{
      slistPtr = new LinkedSortedList<ItemType>();
}
template<class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue& pq)
{
  // created a sorted list
slistPtr = new LinkedSortedList<ItemType>();

// add the items to the list
for (int i = 1; i <= pq.slistPtr->getLength(); i++)
{
  // call the insertedSorted() to add
  slistPtr->insertSorted(pq.slistPtr-> getEntry(i));
}


}
template<class ItemType>
SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{

}
template<class ItemType>
bool SL_PriorityQueue<ItemType>::isEmpty() const
{
  return slistPtr->isEmpty();
}
template<class ItemType>
bool SL_PriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
  return slistPtr->insertSorted(newEntry);
}
template<class ItemType>
bool SL_PriorityQueue<ItemType>::dequeue()
{

return slistPtr->remove(slistPtr->getLength());
}
template<class ItemType>
ItemType SL_PriorityQueue<ItemType>::peekFront() const throw (PrecondViolatedExcept)
{
  if(isEmpty())
  {
    throw PrecondViolatedExcept("peekFront() called with empty queue.");

  }
  	return slistPtr->getEntry(slistPtr->getLength());
}
