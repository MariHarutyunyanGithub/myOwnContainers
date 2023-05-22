// run with ../myVector/myVector.cpp

#include <chrono>
#include <iostream>
#include <random>

#include "../myVector/myVector.h"
#include "../myList/myList.h"

int main() {

    int count_of_elements = 10000;
    std::cout << "\n\t\tLIST VS VECTOR\n\t\tfor " << count_of_elements << " elements\n\n";
    
    MyList<int> list(0);
    auto started = std::chrono::high_resolution_clock::now();
    for (int i{}; i < count_of_elements; ++i) {
        list.push_back(rand());
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "list   push_back() " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end-started).count() << " ms\n";

    Vector vec(1);
    started = std::chrono::high_resolution_clock::now();
    for (int i{}; i < count_of_elements; ++i) {
        const int a = rand();
        vec.push_back(a);
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "vector push_back() " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end-started).count() << " ms\n";
    std::cout << std::endl;



    
    started = std::chrono::high_resolution_clock::now();
    while (!list.isEmpty()) {
        list.pop_back();
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "list   pop_back() : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end-started).count() << " ms\n";

    started = std::chrono::high_resolution_clock::now();
    while (!vec.isEmpty()) {
        vec.pop_back();
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "vector pop_back() : " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(end-started).count() << " ms\n";
    std::cout << std::endl;



    started = std::chrono::high_resolution_clock::now();
    list.insert(1, 4);
    for (int i{}; i < count_of_elements; ++i) {
        list.insert(rand() % list.getItemCount(), rand());
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "list   insert() in random position : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end-started).count() << " ms\n";

    started = std::chrono::high_resolution_clock::now();
    Vector newVec(1);
    newVec.insert(1, 4);
    for (int i{}; i < count_of_elements; ++i) {
        newVec.insert(rand() % list.getItemCount(), rand());
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "vector insert() in random position : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end-started).count() << " ms\n";
    std::cout << std::endl;




    started = std::chrono::high_resolution_clock::now();
    for (int i{}; i < count_of_elements; ++i) {
        list.remove_at(rand() % list.getItemCount());
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "list   remove_at() for random index : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end-started).count() << " ms\n";

    started = std::chrono::high_resolution_clock::now();
    for (int i{}; i < count_of_elements; ++i) {
        newVec.remove_at(rand() % list.getItemCount());
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "vector remove_at() for random index : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end-started).count() << " ms\n";
    std::cout << std::endl;




    MyList<int> newList(1);
    for (int i{}; i < count_of_elements; ++i) {
        newList.push_back(rand());
    }
    started = std::chrono::high_resolution_clock::now();
    newList.clear();
    end = std::chrono::high_resolution_clock::now();
    std::cout << "list   clear() : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end-started).count() << " ms\n";

    Vector vec1(1);
    for (int i{}; i < count_of_elements; ++i) {
        const int a = rand();
        vec1.push_back(a);
    }
    started = std::chrono::high_resolution_clock::now();
    vec1.clear();
    end = std::chrono::high_resolution_clock::now();
    std::cout << "vector clear() : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end-started).count() << " ms\n";
    std::cout << std::endl;




    MyList<int> list1(1);
    for (int i{}; i < count_of_elements; ++i) {
        list1.push_back(rand());
    }
    started = std::chrono::high_resolution_clock::now();
    for (int i{}; i < count_of_elements; ++i) {
        list1.getEntry(1 + rand() % (list1.getItemCount() - 2));
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "list   getEntry() for random index : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end-started).count() << " ms\n";    

    Vector vec2(1);
    for (int i{}; i < count_of_elements; ++i) {
        const int a = rand();
        vec2.push_back(a);
    }
    started = std::chrono::high_resolution_clock::now();
    for (int i{}; i < count_of_elements; ++i) {
        vec2[rand() % (list1.getItemCount() - 2)];
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "vector getEntry() for random index : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end-started).count() << " ms\n";
}