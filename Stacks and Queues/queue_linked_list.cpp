// Implement a Queue class using Linked List approach

#include <iostream>

struct Node {
    int data;
    Node *next;
};

class Queue {
    Node *first;
    Node *last;
    int length;

public:
    Queue() {
        first = nullptr;
        last = nullptr;
        length = 0;
    }

    int size() {
        return length;
    }

    // Return the first value of the Queue
    int peek() {
        if (length <= 0) {
            std::cout << "No elements in Queue" << std::endl;
            return -1;
        }
        // Time Complexity: O(1)
        // Space Complexity: O(1)
        return first->data;
    }

    // Insert a new element at the head (first) of the Queue
    void enqueue(int value) {
        Node *temp = new Node();
        temp->data = value;
        temp->next = nullptr;

        if (first == nullptr) {
            first = temp;
            last = temp;
            temp = nullptr;
            length++;
            return;
        }

        last->next = temp;
        last = temp;
        length++;

        // Time Complexity: O(1)
        // Space Complexity: O(1)
        return;
    }

    // Return the head (first) and delete it from the Queue
    int dequeue() {
        if (length <= 0) {
            std::cout << "No elements in Queue" << std::endl;
            return -1;
        }

        if (length == 1) {
            int ret = first->data;
            first = nullptr;
            last = nullptr;
            length--;
            return ret;
        }

        int ret = first->data;
        Node *temp = new Node();
        temp = first;
        first = first->next;
        length--;
        delete temp;

        // Time Complexity: O(1)
        // Space Complexity: O(1)

        return ret;
    }

    // Print out the Queue
    void print_queue() {
        if (length <= 0) {
            std::cout << "Queue is empty - nothing to display" << std::endl;
            return;
        }

        Node *curr = new Node();
        curr = first;
        std::cout << "First: " << std::flush;
        while (curr != nullptr) {
            std::cout << curr->data << "\t" << std::flush;
            curr = curr->next;
        }
        std::cout << ": Last\n"
                  << std::flush;
    }

    void free_memory() {
        Node *temp = new Node;
        while (first != NULL) {
            temp = first;
            first = first->next;
            delete temp;
        }
    }
};

int main() {
    Queue myQueue = Queue();
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);

    myQueue.print_queue();

    std::cout << "Peeking: " << myQueue.peek() << std::endl;

    std::cout << "Popping: " << myQueue.dequeue() << std::endl;
    myQueue.print_queue();
    std::cout << "Popping: " << myQueue.dequeue() << std::endl;
    myQueue.print_queue();
    std::cout << "Popping: " << myQueue.dequeue() << std::endl;
    myQueue.print_queue();
    std::cout << "Popping: " << myQueue.dequeue() << std::endl;
    myQueue.print_queue();
    std::cout << "Popping: " << myQueue.dequeue() << std::endl;
    myQueue.print_queue();

    std::cout << "Size: " << myQueue.size() << std::endl;

    std::cout << "Popping: " << myQueue.dequeue() << std::endl;
    myQueue.print_queue();
    std::cout << "Popping: " << myQueue.dequeue() << std::endl;
    myQueue.print_queue();

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);

    myQueue.print_queue();

    myQueue.free_memory();
    return 0;
}