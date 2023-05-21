#include <iostream>
#include "myForwardList.h"

int main() {
    
    FList<int> obj1(5);//5
    obj1.insert(1,1);//1 5
    obj1.insert(2,2);//1 2 5
    obj1.insert(3,3);//1 2 3 5
    obj1.insert(4,4);//1 2 3 4 5
    obj1.insert(4,9);//1 2 3 9 4 5
    obj1.insert(4,6);//1 2 3 6 9 4 5

    FList<int> obj(9);
    obj.insert(1,6);//6 9
    obj.insert(2,7);//6 7 9
    obj.insert(3,8);//6 7 8 9

    std::cout << obj << std::endl;
    std::cout << obj1 << std::endl;

    FList<int> obj2;
    obj2 = obj + obj1;   

    std::cout << "my new list : " << obj2 << std::endl;
    return 0;
}
