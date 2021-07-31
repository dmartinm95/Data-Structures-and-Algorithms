#include <iostream>

// Singly Linked List Implementation
struct Node {
    int data;
    Node *next;
};

class List {
    Node *head;
    Node *tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    // Create node
    void list_create_node(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;

        if (head == NULL) {
            // If the list is empty, set both the head and the tail to the single node
            head = temp;
            tail = temp;
            temp = NULL;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Display the Linked List
    void list_display() {
        Node *temp = new Node;
        temp = head;
        while (temp != NULL) {
            std::cout << temp->data << "\t";
            temp = temp->next;
        }

        std::cout << std::endl;
    }

    void list_insert_start(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void list_insert_end(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }

    // Insertion at a particular position
    void list_insert_position(int value, int pos) {
        Node *temp = new Node;
        Node *curr = new Node;
        Node *prev = new Node;

        // Initialize curr to start at the head of the list
        curr = head;

        // Iterate through until we reach the desired position
        // Head starts at pos = 1
        for (int i = 1; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }

        temp->data = value;
        prev->next = temp;
        temp->next = curr;
    }

    void list_delete_start() {
        Node *temp = new Node;
        temp = head;
        head = head->next;
        delete temp;
    }

    void list_delete_end() {
        Node *curr = new Node;
        Node *prev = new Node;
        curr = head;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        tail = prev;
        prev->next = NULL;
        delete curr;
    }

    void list_delete_position(int pos) {
        Node *curr = new Node;
        Node *prev = new Node;
        curr = head;
        for (int i = 1; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
    }

    // Remove nodes from memory
    void list_free_memory() {
        Node *temp = new Node;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void list_reverse() {

        if (head->next == NULL) {
            return;
        }

        Node *first = new Node;
        Node *second = new Node;

        first = head;
        second = first->next;
        tail = first;

        while (second != NULL) {
            Node *temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }

        head->next = NULL;
        head = first;
    }
};

int main() {

    List list = List();
    // list.list_create_node(1);
    // list.list_insert_start(0);
    // list.list_insert_end(2);
    // list.list_insert_end(3);
    // list.list_insert_end(4);
    // list.list_insert_position(10, 5);
    // list.list_delete_start();
    // list.list_delete_start();
    // list.list_delete_end();
    // list.list_delete_position(2);
    // list.list_display();

    list.list_create_node(1);
    list.list_insert_end(10);
    list.list_insert_end(16);
    list.list_insert_end(88);
    list.list_display();
    list.list_reverse();
    list.list_display();
    list.list_free_memory();

    return 0;
}