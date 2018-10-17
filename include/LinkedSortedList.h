#ifndef LINKED_SORTED_LIST
#define LINKED_SORTED_LIST


#include <memory>
#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"


template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
private:
  std::shared_ptr<Node<ItemType> > headPtr; // poins to first node in the chain
  int items; //list item count
  //locates the node or given node that shiuld or does contain the entry thats given
  std::shared_ptr<Node<ItemType> > getNodeBefore(const ItemType& anEntry) const;

  std::shared_ptr<Node<ItemType> > getNodeAt(int position) const; // locates the node at any positing in the chain

  std::shared_ptr<Node<ItemType> > copychain(const std::shared_ptr<Node<ItemType>>&origChainPtr);  // returns a pointer to a copy of the chain in whic origChainPtr points to

public:

  LinkedSortedList();
  LinkedSortedList(const LinkedSortedList<ItemType>&aList);
  virtual ~LinkedSortedList();
  bool  insertSorted(const ItemType& newEntry);
  bool  removeSorted(const ItemType& anEntry);
  int  getPosition(const ItemType& newEntry) const;


  //methods same as given in ListInterface

  bool isEmpty() const;
  int getLength() const;
  bool remove(int position);
  void clear();
std::shared_ptr<Node<ItemType> > getEntry(int position) const throw(PrecondViolatedExcept);
}; //end LinkedSortedList


#endif
