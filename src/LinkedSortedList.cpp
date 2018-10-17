#include "LinkedSortedList.h"
#include "Node.cpp"
#include <memory>


template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList()
{
  headPtr = nullptr;
  items = 0;

}
template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>&aList)
{
  //copy constructor
  headPtr = copychain(aList.headPtr);
  items = aList.items;
}
template<class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{

  //destructor
}
template<class ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{

std::shared_ptr<Node<ItemType> > newNodePtr(std::make_shared<Node<ItemType> > (newEntry));
std::shared_ptr<Node<ItemType> > prevPtr = getNodeBefore(newEntry);

// Adding at the beggining
if(isEmpty() || (prevPtr == nullptr))
{
  newNodePtr->setNext(headPtr);
  headPtr = newNodePtr;
}
else          // or add at the node before
{
  std::shared_ptr<Node<ItemType> > aftPtr = prevPtr->getNext();
  newNodePtr->setNext(aftPtr);
  prevPtr->setNext(newNodePtr);
}	// end if

items++;
return true;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
  bool canDelete = false;

// Check if queue is empty
if(!isEmpty())
{
// pointer
std::shared_ptr<Node<ItemType> > nodeRmPtr = headPtr;

std::shared_ptr<Node<ItemType> > prevPtr = getNodeBefore(anEntry);

// check previous pointer is not null
if(prevPtr != nullptr)
  nodeRmPtr = prevPtr->getNext();

canDelete = (nodeRmPtr != nullptr) && (anEntry == nodeRmPtr->getItem());

if(canDelete)
{
  std::shared_ptr<Node<ItemType> > aftPtr = nodeRmPtr->getNext();

  // if node equals head
  if(nodeRmPtr == headPtr)
  {
    // assign headptr
    headPtr = aftPtr;
  }

  else
  {
    prevPtr->setNext(aftPtr);
  }



  items--;
}
}
return canDelete;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& newEntry) const
{
  int position = 1;

    std::shared_ptr<Node<ItemType> > curPtr = headPtr; //assigning the headptr to the current pointer in the list



  while((curPtr != nullptr)&& (newEntry > curPtr->getItem()))
  {
    curPtr = curPtr->getNext(); // we are assiging next to our current pointer
    position++;
  }

  if((curPtr == nullptr) || (newEntry != curPtr->getItem()))
  {
    position = -position;
  }
  return position;



}
template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
  return  items == 0;
}
template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
  return items;
}
template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position)
{
  bool ableforDeletion = (position >= 1) && (position <= items);

  if(ableforDeletion)
  {
    std::shared_ptr<Node<ItemType> > curPtr = nullptr;
    if(position == 1)
    {
      // to delete first node in the chain
      curPtr = headPtr; //saves pointer to node
      headPtr = headPtr->getNext();
    }
    else
    {
    std::shared_ptr<Node<ItemType> > prevPtr = getNodeAt(position -1);
    curPtr = prevPtr->getNext();
    prevPtr->setNext(curPtr->getNext());
    }

    items--;


  }
  return ableforDeletion;
}
template<class ItemType>
void LinkedSortedList<ItemType>::clear()
{
  while(!isEmpty())
  {
    remove(1);    // loops until sorted list is empty
  }
}
template<class ItemType>
ItemType  LinkedSortedList<ItemType>:: getEntry(int position) const throw(PrecondViolatedExcept)
{
  bool abletoget =(position >= 1) && (position <= items);

  if(abletoget)
  {
    std::shared_ptr<Node<ItemType> > nodePtr = getNodeAt(position);
    return nodePtr->getItem();
  }
  else
  {
    std::string message = "getEntry() called with an empty list or";
    message = message + "invalid position.";
    throw(PrecondViolatedExcept(message));
  }
}
template<class ItemType>
std::shared_ptr<Node<ItemType> > LinkedSortedList<ItemType>::copychain(const std::shared_ptr<Node<ItemType>>& origChainPtr)
{
	std::shared_ptr<Node<ItemType>> copiedChainPtr;	// Initial value is nullptr
	if (origChainPtr != nullptr)
	{
		// Build new chain from given one, Create new node with the current item
		copiedChainPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem());

		copiedChainPtr->setNext(copyChain(origChainPtr->getNext())); // makes the node point to the rest of the chain
	}
	return copiedChainPtr;
}
template<class ItemType>
std::shared_ptr<Node<ItemType> > LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{

	std::shared_ptr<Node<ItemType> > curPtr = headPtr;
	std::shared_ptr<Node<ItemType>> prevPtr;


	while( (curPtr != nullptr) && (anEntry > curPtr->getItem()) )
	{
		prevPtr = curPtr;
		curPtr = curPtr->getNext();
	}
	return prevPtr;
}
template<class ItemType>
std::shared_ptr<Node<ItemType> > LinkedSortedList<ItemType>::getNodeAt(int position) const
{

	std::shared_ptr<Node<ItemType> > curPtr = headPtr;

	for(int i = 1; i < position; i++)
  {
    curPtr = curPtr->getNext();
  }


	return curPtr;
}
