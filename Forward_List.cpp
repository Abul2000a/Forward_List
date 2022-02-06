#include <iostream>
#include "Forward_List.hpp"

int main()
{
    List<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(22);
    lst.push_front(13);
    lst.insert(15,2);
    lst.removeAt(2);
    lst.pop_back();
    for(int i = 0; i < lst.getSize(); i++)
    {
        std::cout << lst[i] << std::endl;
    }
}