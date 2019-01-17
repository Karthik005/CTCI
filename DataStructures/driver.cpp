#include"DataStructures.hpp"
#include "LinkedList.cpp"
#include "ArrayList.cpp"
#include <iostream>

int main_LL(int argc, char const *argv[])
{
    LinkedList<int> linkedList = LinkedList<int>();
    linkedList.insertEnd(linkedList.createNode(10));
    linkedList.insertEnd(linkedList.createNode(34));
    linkedList.printList();
    std::cout << linkedList.search(-10)<<std::endl;
    return 0;
}


int main(){
    ArrayList<int> intList = ArrayList<int>(2);
    intList.append(10);
    intList.append(12);
    intList.append(12);
    intList.append(12);
    intList.append(12);
    intList.printList();
    std::cout<<intList.search(10)<<endl;
}