// Implement a Stack class using Linked List approach

#include <iostream>

struct Node {
    int data;
    Node *next;
};

class Stack {
    Node *top;
    Node *bottom;
    int length;

public:
    Stack() {
        top = nullptr;
        bottom = nullptr;
        length = 0;
    }

    int size() {
        return length;
    }

    // Return the value of the top of the stack
    int peek() {
        if (length <= 0) {
            std::cout << "No elements in Stack" << std::endl;
            return -1;
        }
        // Time Complexity: O(1)
        // Space Complexity: O(1)
        return top->data;
    }

    // Insert a new element at the top of the stack
    void push(int value) {
        Node *temp = new Node();
        temp->data = value;
        temp->next = nullptr;

        if (bottom == nullptr) {
            bottom = temp;
            top = temp;
            temp = nullptr;
            length++;
            return;
        }

        top->next = temp;
        top = temp;

        length++;

        // Time Complexity: O(1)
        // Space Complexity: O(1)
        return;
    }

    // Return the top and delete it from the stack
    int pop() {
        if (length <= 0) {
            std::cout << "No elements in Stack" << std::endl;
            return -1;
        }

        if (length == 1) {
            int ret = bottom->data;
            bottom = nullptr;
            top = nullptr;
            length--;
            return ret;
        }

        Node *curr = new Node();
        Node *prev = new Node();

        curr = bottom;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }

        top = prev;
        prev->next = nullptr;

        int ret = curr->data;

        delete curr;

        length--;

        // Time Complexity: O(n)
        // Space Complexity: O(1)

        return ret;
    }

    // Print out the stack
    void print_stack() {
        if (length <= 0) {
            std::cout << "Stack is empty - nothing to display" << std::endl;
            return;
        }

        Node *curr = new Node();
        curr = bottom;
        std::cout << "Bottom: " << std::flush;
        while (curr != nullptr) {
            std::cout << curr->data << "\t" << std::flush;
            curr = curr->next;
        }
        std::cout << ": Top\n"
                  << std::flush;
    }

    void free_memory() {
        Node *temp = new Node;
        while (bottom != NULL) {
            temp = bottom;
            bottom = bottom->next;
            delete temp;
        }
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

    myStack.free_memory();
    return 0;
}