#include <iostream>
using namespace std;

// Node class
class Node 
{
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int val) : data(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    int getHeight(Node* node) 
    {
        return node ? node->height : 0;
    }

    // Update the height of a node
    void updateHeight(Node* node) 
    {
        if (node) 
        {
            int leftHeight = getHeight(node->left);
            int rightHeight = getHeight(node->right);
            node->height = max(leftHeight, rightHeight) + 1;
        }
    }

    int getBalanceFactor(Node* node) 
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* rotateLeft(Node* x) 
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* rotateRight(Node* y) 
    {
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

    Node* rebalance(Node* node) 
    {
        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1) 
        {

            if (getBalanceFactor(node->left) < 0) 
            {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }

        if (balanceFactor < -1) 
        {
            if (getBalanceFactor(node->right) > 0) 
            {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

    Node* rebalanceTree(Node* root) 
    {
        if (!root) return nullptr;

        root->left = rebalanceTree(root->left);
        root->right = rebalanceTree(root->right);

        return rebalance(root);
    }
    void inOrder(Node* root) 
    {
        if (root) 
        {
            inOrder(root->left);
            cout << "Node: " << root->data << ", Balance Factor: " << getBalanceFactor(root) << endl;
            inOrder(root->right);
        }
    }

public:

    Node* root;

    AVLTree() : root(nullptr) {}

    void rebalanceTree() 
    {
        root = rebalanceTree(root);
    }
    void printTree() 
    {
        inOrder(root);
    }
};

int main() 
{
    AVLTree tree;

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

    tree.printTree();

    tree.rebalanceTree();

    cout << endl;
    
    tree.printTree();

    return 0;
}