#include <iostream>
#include "myQueue.h"

int main() {
    MyQueue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.pop();
    std::cout << "queue : "<< Q << std::endl;
    std::cout << "size : " << Q.size() << std::endl;    
    std::cout << "top : " << Q.peek() << std::endl;
    std::cout << "isEmpty : " << Q.isEmpty() << std::endl;
    Q.clear();
    std::cout << "queue after clear : " << Q << std::endl;
    std::cout << "isEmpty : " << Q.isEmpty() << std::endl;
    Q.push(3);
    Q.push(4);
    std::cout << "queue : " << Q << std::endl;
}