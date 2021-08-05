// Implement a Stack class using Array/Vector approach
#include <iostream>
#include <vector>

class Stack {
    std::vector<int> values;

public:
    Stack() {
        values = {};
    }

    int size() {
        return values.size();
    }

    // Return the value of the top of the stack
    int peek() {
        if (values.size() <= 0) {
            std::cout << "No elements in Stack" << std::endl;
            return -1;
        }
        // Time Complexity: O(1)
        // Space Complexity: O(1)
        return values[values.size() - 1];
    }

    // Insert a new element at the top of the stack
    void push(int value) {
        values.push_back(value);
        // Time Complexity: O(1)
        // Space Complexity: O(1)
        return;
    }

    // Return the top and delete it from the stack
    int pop() {
        if (values.size() <= 0) {
            std::cout << "No elements in Stack" << std::endl;
            return -1;
        }

        int ret = values[values.size() - 1];
        values.pop_back();

        // Time Complexity: O(1)
        // Space Complexity: O(1)
        return ret;
    }

    // Print out the stack
    void print_stack() {
        if (values.size() <= 0) {
            std::cout << "Stack is empty - nothing to display" << std::endl;
            return;
        }

        std::cout << "Bottom: " << std::flush;
        for (int num : values) {
            std::cout << num << "\t" << std::flush;
        }
        std::cout << ": Top" << std::endl;
    }
};

int main() {

    Stack myStack = Stack();
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    myStack.push(6);

    myStack.print_stack();

    std::cout << "Peeking: " << myStack.peek() << std::endl;

    std::cout << "Popping: " << myStack.pop() << std::endl;
    myStack.print_stack();
    std::cout << "Popping: " << myStack.pop() << std::endl;
    myStack.print_stack();
    std::cout << "Popping: " << myStack.pop() << std::endl;
    myStack.print_stack();
    std::cout << "Popping: " << myStack.pop() << std::endl;
    myStack.print_stack();
    std::cout << "Popping: " << myStack.pop() << std::endl;
    myStack.print_stack();

    std::cout << "Size: " << myStack.size() << std::endl;

    std::cout << "Popping: " << myStack.pop() << std::endl;
    myStack.print_stack();
    std::cout << "Popping: " << myStack.pop() << std::endl;
    myStack.print_stack();

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    myStack.push(6);

    myStack.print_stack();

    return 0;
}