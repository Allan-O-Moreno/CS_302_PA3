#include "LinkedSortedList.cpp"
#include "SL_PriorityQueue.cpp"
#include <iostream>
#include <memory>
#include<string>


int main()
{
  std::string name = "Abigail";

  //for(auto i : name) {

  //}
  SL_PriorityQueue<char> q;
  for(unsigned int i = 0; i < name.length(); ++i)
  {
    q.enqueue(name[i]);


  }

  for(unsigned int j = 0; j < name.length(); ++j)
  {

    std::cout << q.peekFront() << " " ;
    q.dequeue();
  }



/*
  std::shared_ptr<LinkedSortedList<char> > names(new LinkedSortedList<char>());
  names->insertSorted('a');
  std::cout << names->getPosition('a') << std::endl;
  names->insertSorted('b');
  std::cout << names->getPosition('b') << std::endl;
  */
}
