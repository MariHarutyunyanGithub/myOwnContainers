#include <iostream>
#include "myList.h"

int main() {
    int a = 11;
    int b = 5;
    // MyList<int>* newList = new MyList<int>; // default c_tor
    // newList->insert(1,5); // 5
    // newList->insert(1, 8); // 8 5
    // newList->insert(2, 0); // 8 5 0
    // std::cout << "newList : " << *newList << std::endl;
    MyList<int> list(5);
    MyList<int> obj(9);
    list.insert(1,1); // 1 5
    list.insert(3,6); // 1 5 6
    list.insert(4,9); // 1 5 6 9
    list.insert(2,2); // 1 2 5 6 9
    list.insert(3,11); // 1 2 11 5 6 9
    std::cout << list.getHead()->getItem() << std::endl;
    std::cout << "currentList " << list << std::endl;
    std::cout << "itemCount :" << list.getItemCount() << std::endl;
    list.pop_back(); // 1 2 11 5 6
    list.pop_front(); // 2 11 5 6
    list.push_back(12); // 2 11 5 6 12
    list.push_back(17); // 2 11 5 6 12 17
    list.push_back(200);
    std::cout << "tail : " << list.getTail()->getItem() << std::endl;
    list.remove_at(4); // 2 11 5 12 17
    list.remove(a); // 2 5 12 17 
    list.remove(17); // 2 5 12
    std::cout << "currentList " << list << std::endl;

    obj.insert(1,6);//6 9
    obj.insert(2,7);//6 7 9
    obj.insert(3,8);//6 7 8 9
    std::cout << obj << std::endl;

    MyList<int> obj2 = list; // copy c_tor 
    
    obj += list;
    std::cout << "obj2 : " << obj2 << std::endl;
    std::cout << "my new list : " << obj << std::endl;

    obj.setEntry(2, 0);
    std::cout << obj.getEntry(2) << std::endl;
    std::cout << "my new list : " << obj << std::endl;

    std::cout << "isEmplty : " << list.isEmpty() << std::endl;
    std::cout << obj << std::endl;
    obj.clear();
    std::cout << obj.isEmpty() << std::endl;
    return 0;
}
