#include "LinkedSortedList.cpp"
//#include "SL_PriorityQueue.cpp"
#include <iostream>
#include <memory>


int main()
{
  //SL_PriorityQueue<int> q;
  //q.enqueue(1);
  std::shared_ptr<LinkedSortedList<char> > names(new LinkedSortedList<char>());
  names->insertSorted('a');
  std::cout << names->getPosition('a') << std::endl;
  names->insertSorted('b');
  std::cout << names->getPosition('b') << std::endl;
}
