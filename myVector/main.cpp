#include <iostream>

#include "myVector.h"

int main() {
    Vector vec;
    int a = 6;
    vec.push_back(a);
    vec.push_back(4);
    vec.push_back(0);
    vec.pop_back();
    vec.insert(2, 0);
    std::cout << vec << std::endl;
    int index = vec.find_by_value(4);
    std::cout << index << std::endl;
    vec.remove_by_value(4);
    std::cout << vec << std::endl;
    vec.insert(1, 2);
    vec.insert(1, 9);
    std::cout << vec << std::endl;
    vec.remove_at(2);
    std::cout << vec << std::endl;
    std::cout << vec.isEmpty() << std::endl;
    vec.clear();
    std::cout << vec << std::endl;
}