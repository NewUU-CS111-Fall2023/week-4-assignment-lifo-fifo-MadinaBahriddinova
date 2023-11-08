/*
 * Author:
 * Date:08.11.2023
 * Name:Madina Bahriddinova
 */

#include <iostream>
#include <stack>
#include <string>
#include "task_1.h"

int main() {
    std::cout << "Task 1" << std::endl;
    Stack stack;
    stack.push(2);
    stack.push(7);
    stack.push(9);
    stack.push(58);

    std::cout << "The top element is: " << stack.topValue() << std::endl;

    std::cout << "The popped element is: " << stack.pop() << std::endl;
    std::cout << "The popped element is: " << stack.pop() << std::endl;

    if(stack.isEmpty()==1){
        std::cout<<"Stack is empty"<<std::endl;
    }
    else{
        std::cout<<"Stack is not empty!";
    }
    return 0;
    
    std::cout << "Task 2" << std::endl;
    
    
    std::cout << "Task 3" << std::endl;
    std::string str;
    std::getline(std::cin, str);

    int result = PostfixExpresion(str);

    std::cout << result << std::endl;

    return 0;
    
    
    std::cout << "Task 4" << std::endl;
    // call for task 4
    std::cout << "Task 5" << std::endl;
    // call for task 5
    return 0;
}
