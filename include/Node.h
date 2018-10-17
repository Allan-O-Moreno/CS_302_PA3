// #ifndef NODE_H_
// #define NODE_H_
#pragma once

#include<memory>
template<class ItemType>
class Node
{
private:
	ItemType item;	// A data item
	std::shared_ptr<Node<ItemType> > next; // A pointer to next node
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, std::shared_ptr<Node<ItemType> > nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(std::shared_ptr<Node<ItemType> > nextNodePtr);
  ItemType getItem() const;
	std::shared_ptr<Node<ItemType> >  getNext() const;
};

// #include "Node.cpp"
// #endif /* NODE_H_ */
