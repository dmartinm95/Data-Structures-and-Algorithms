#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;
};

class Doubly {
    Node *head;
    Node *tail;

public:
    Doubly() {
        head = nullptr;
        tail = nullptr;
    }

    void list_create_node(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr) {
            temp->prev = nullptr;
            head = temp;
            tail = temp;
            temp = nullptr;
        } else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void list_insert_head(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->prev = nullptr;
        temp->next = head;

        head = temp;
    }

    void list_insert_tail(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        temp->prev = tail;

        tail->next = temp;
        tail = temp;
    }

    void list_insert_position(int pos, int value) {
        Node *curr = new Node;
        Node *prev = new Node;
        Node *temp = new Node;

        curr = head;

        for (int i = 1; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }

        temp->data = value;
        temp->next = curr;
        temp->prev = prev;

        prev->next = temp;

        curr->prev = temp;
    }

    void list_delete_head() {
        Node *temp = new Node;
        temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    void list_delete_tail() {
        Node *temp = new Node;
        temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    void list_delete_position(int pos) {
        Node *curr = new Node;
        Node *prev = new Node;
        Node *temp = new Node;

        curr = head;

        for (int i = 1; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }

        temp = curr->next;
        prev->next = curr->next;
        temp->prev = curr->prev;
        delete curr;
    }

    void list_display() {
        Node *curr = new Node;
        curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << "\t";
            curr = curr->next;
        }
    }

    void list_free_memory() {
        Node *temp = new Node;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {

    Doubly doubly = Doubly();
    doubly.list_create_node(0);
    doubly.list_insert_head(1);
    doubly.list_insert_tail(2);
    doubly.list_insert_head(1);
    doubly.list_insert_tail(2);
    doubly.list_insert_position(3, 44);
    doubly.list_delete_head();
    doubly.list_delete_tail();
    doubly.list_delete_position(3);
    doubly.list_display();

    doubly.list_free_memory();

    return 0;
}