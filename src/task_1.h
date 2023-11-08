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

int PostfixExpresion(std::string str) {
    std::stack<int> operand;

    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            operand.push(str[i] - '0'); 
        } else {
            int operand2 = operand.top();
            operand.pop();
            int operand1 = operand.top();
            operand.pop();

            switch (str[i]) {
                case '+':
                    operand.push(operand1 + operand2);
                    break;
                case '-':
                    operand.push(operand1 - operand2);
                    break;
                case '*':
                    operand.push(operand1 * operand2);
                    break;
            }
        }
    }

    return operand.top();
}
