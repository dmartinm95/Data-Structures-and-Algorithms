#include <iostream>

struct Node {
    int value;
    Node *left;
    Node *right;
};

class BinarySearchTree {

public:
    Node *root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;

        Node *curr = new Node;
        curr = root;

        Node *prev = nullptr;

        while (curr != nullptr) {
            prev = curr;
            if (value > curr->value) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        if (prev == nullptr) {
            root = newNode;
        } else if (value > prev->value) {
            prev->right = newNode;
        } else {
            prev->left = newNode;
        }
    }

    void inOrderTraversal(Node *root) {
        if (root == nullptr) {
            return;
        } else {
            inOrderTraversal(root->left);
            std::cout << root->value << " ";
            inOrderTraversal(root->right);
        }
    }

    void deleteNode(int value) {
        Node *curr = root;
        Node *prev = nullptr;

        // Check if the key exists in the BST
        // prev points to the parent of the key to be deleted
        while (curr != nullptr && curr->value != value) {
            prev = curr;
            if (value < curr->value) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (curr == NULL) {
            // Did not find the key
            std::cout << "Key: " << value << " not found in the BST.\n";
            return;
        }

        // Check if the node to be deleted has atmost one child
        if (curr->left == nullptr || curr->right == nullptr) {
            Node *newCurr;

            // If the left child does not exist
            if (curr->left == nullptr) {
                newCurr = curr->right;
            } else {
                newCurr = curr->left;
            }

            // Check if the node to be deleted is the root
            if (prev == nullptr) {
                root = newCurr;
            }

            // Replace node to be deleted with either the right or left child
            if (curr == prev->left) {
                prev->left = newCurr;
            } else {
                prev->right = newCurr;
            }

            delete (curr);
        }
        // Node to be deleted has 2 children
        else {
            Node *p = nullptr;
            Node *temp;

            // Compute the inorder successor
            temp = curr->right;
            while (temp->left != nullptr) {
                p = temp;
                temp = temp->left;
            }

            if (p != nullptr) {
                p->left = temp->right;
            } else {
                curr->right = temp->right;
            }

            curr->value = temp->value;
            delete temp;
        }
    }

    bool lookup(int value) {
        Node *curr = new Node;
        curr = root;

        while (curr != nullptr) {
            if (value > curr->value) {
                curr = curr->right;
            } else if (value < curr->value) {
                curr = curr->left;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {

    BinarySearchTree bst = BinarySearchTree();

    /*
         10
        /  \
       7    15
      / \   / \
      5  8 11 18
 
    */
    bst.insert(10);
    bst.insert(7);
    bst.insert(5);
    bst.insert(8);
    bst.insert(15);
    bst.insert(11);
    bst.insert(18);

    std::cout << "Inorder traversal of original BST:\n";
    bst.inOrderTraversal(bst.root);
    std::cout << "\n";

    // Leaf node
    bst.deleteNode(11);
    std::cout << "\nDeletion of 11\n";
    std::cout << "Inorder traversal post deletion:\n";
    bst.inOrderTraversal(bst.root);
    std::cout << "\n";

    // Internal node with one child
    bst.deleteNode(15);
    std::cout << "\nDeletion of 15\n";
    std::cout << "Inorder traversal post deletion:\n";
    bst.inOrderTraversal(bst.root);
    std::cout << "\n";

    // Root node with 2 children
    bst.deleteNode(10);
    std::cout << "\nDeletion of 10\n";
    std::cout << "Inorder traversal post deletion:\n";
    bst.inOrderTraversal(bst.root);
    std::cout << "\n";

    return 0;
}