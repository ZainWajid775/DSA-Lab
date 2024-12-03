#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int val) : data(val), height(1), left(nullptr), right(nullptr) {}
};

// AVL Tree class
class AVLTree {
private:
    // Get the height of a node
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    // Update the height of a node
    void updateHeight(Node* node) {
        if (node) {
            int leftHeight = getHeight(node->left);
            int rightHeight = getHeight(node->right);
            node->height = max(leftHeight, rightHeight) + 1;
        }
    }

    // Get the balance factor of a node
    int getBalanceFactor(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Left rotation
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Right rotation
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Rebalance the node
    Node* rebalance(Node* node) {
        int balanceFactor = getBalanceFactor(node);

        // Left heavy
        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) < 0) {
                // Left-Right case
                node->left = rotateLeft(node->left);
            }
            // Left-Left case
            return rotateRight(node);
        }

        // Right heavy
        if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) > 0) {
                // Right-Left case
                node->right = rotateRight(node->right);
            }
            // Right-Right case
            return rotateLeft(node);
        }

        return node;
    }

    // Recursive function to rebalance the entire tree
    Node* rebalanceTree(Node* root) {
        if (!root) return nullptr;

        // Rebalance the left and right subtrees
        root->left = rebalanceTree(root->left);
        root->right = rebalanceTree(root->right);

        // Rebalance the current node
        return rebalance(root);
    }

    // Recursive function to print the tree (in-order traversal)
    void inOrder(Node* root) {
        if (root) {
            inOrder(root->left);
            cout << "Node: " << root->data << ", Balance Factor: " << getBalanceFactor(root) << endl;
            inOrder(root->right);
        }
    }

public:
    Node* root;

    AVLTree() : root(nullptr) {}

    // Wrapper for rebalanceTree
    void rebalanceTree() {
        root = rebalanceTree(root);
    }

    // Function to print the tree
    void printTree() {
        inOrder(root);
    }
};

int main() {
    AVLTree tree;

    // Creating the BST resulting from Task 2 (after removing 5 without rebalancing)
    tree.root = new Node(4);
    tree.root->left = new Node(3);
    tree.root->left->left = new Node(2);
    tree.root->left->left->left = new Node(1);
    tree.root->right = new Node(10);
    tree.root->right->left = new Node(7);
    tree.root->right->left->left = new Node(6);
    tree.root->right->left->right = new Node(9);
    tree.root->right->left->right->left = new Node(8);
    tree.root->right->right = new Node(11);
    tree.root->right->right->right = new Node(12);

    cout << "Tree before rebalancing:\n";
    tree.printTree();

    // Task 3: Rebalance the tree
    tree.rebalanceTree();
    cout << "\nTree after rebalancing:\n";
    tree.printTree();

    return 0;
}