/*
 * Author:
 * Date:
 * Name:
 */
struct Struct {
    int a;
    Struct* next;
};

// Stack class
class Stack {
private:
    Struct* top;

public:
    // Constructor
    Stack() {
        top = nullptr;
    }
    bool isEmpty() {
        return top == nullptr;
    }

    // Push an element to the top of the stack
    void push(int b) {
        Struct* newStruct = new Struct();
        newStruct->a = b;
        newStruct->next = top;
        top = newStruct;
        std::cout << b << " pushed to stack" << std::endl;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1; // Return -1 in case of empty stack
        }
        int poppedValue = top->a;
        Struct* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int topValue() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1; // Return -1 in case of empty stack
        }
        return top->a;
    }
};
