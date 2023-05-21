#include <iostream>

#include "myVector.h"

int main() {
    Vector vec;
    int a = 6;
    vec.push_back(a);
    vec.push_back(4);
    vec.push_back(0);
    std::cout << vec << std::endl;
}