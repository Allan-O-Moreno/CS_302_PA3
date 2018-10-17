// #ifndef PRIORITY_QUEUE_
// #define PRIORITY_QUEUE_
#pragma once

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcept.h"
#include <memory>


template<class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
private:

    std::unique_ptr<LinkedSortedList<ItemType>> slistPtr;

public:

  SL_PriorityQueue();
  SL_PriorityQueue(const SL_PriorityQueue& pq);
  ~SL_PriorityQueue();

  bool isEmpty() const;
  bool enqueue (const ItemType& newEntry);
  bool dequeue();


  // throwing PrecondViolatedExcept
  ItemType peekFront() const throw (PrecondViolatedExcept);


};   //end class

// #include "SL_PriorityQueue.cpp"
// #endif
