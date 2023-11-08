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


bool solve(std::vector<std::stack<int>>& stacks, int a) {
    std::vector<int> targetPosition(a+1, 0); 
    
    for (int i = 1; i <= a; i++) {
        targetPosition[i] = i;
    }
    
    int from = -1, to = -1;
    
    for (int i = 0; i < stacks.size(); i++) {
        std::stack<int> s = stacks[i];
        while (!s.empty()) {
            int container = s.top();
            s.pop();
            
            if (container != targetPosition[container]) {
                for (int j = 0; j < stacks.size(); j++) {
                    if (!stacks[j].empty() && stacks[j].top() == targetPosition[container]) {
                        from = i + 1;
                        to = j + 1;
                        break; 
                    }
                }
                
                if (from == -1 || to == -1) {
                    return false;
                }
                
                stacks[from-1].pop();
                stacks[to-1].push(container);
                std::cout << from << " " << to <<std::endl;
            }
        }
    }
    
    return true;
}
