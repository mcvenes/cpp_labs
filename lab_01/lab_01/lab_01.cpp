#include <iostream>
#include <string>

#include "MyStack.h"


int main()
{
    std::cout << "Hello World!\n";

    MyStack<std::string> stack(3);

    std::cout << "stack size: " << stack.size() << ", max size: " << stack.capacity() << std::endl;

    return 0;
}