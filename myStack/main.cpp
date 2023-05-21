#include <iostream>
#include "myStack.h"

int main() {
    MyStack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    std::cout << "stack : "<< st << std::endl;
    std::cout << "size : " << st.size() << std::endl;    
    std::cout << "top : " << st.peek() << std::endl;
    std::cout << "isEmpty : " << st.isEmpty() << std::endl;
    st.clear();
    std::cout << "stack after clear : " << st << std::endl;
    std::cout << "isEmpty : " << st.isEmpty() << std::endl;
    st.push(3);
    st.push(4);
    std::cout << "stack : " << st << std::endl;
}