#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) : data(val) , left(nullptr) , right(nullptr) , height(1) {}
};

int height(Node* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return root->height;
}

void update_height(Node* node)
{
    if(node != nullptr)
    {
        node->height = 1 + max(height(node->left) , height(node->right));
    }
}

Node* insert(Node* root , int val)
{
    //Insert new node if position found
    if(root == nullptr)
    {
        return new Node(val);
    }

    //Recursively call itself with a new node until nullptr is found
    if(val < root->data)
    {
        root->left = insert(root->left , val);
    }
    else
    {
        root->right = insert(root->right , val);
    }

    update_height(root);

    return root;
}

bool search(Node* root , int val)
{
    if(root == nullptr)
    {
        return false;
    }

    //Check value of current node
    if(val == root->data)
    {
        return true;
    }

    //Continue searching left or right depending on value being greater or larger than node data
    if(val < root->data)
    {
        return search(root->left , val);
    }
    else
    {
        return search(root->right , val);
    }
}
void in_order(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    in_order(root->left);
    cout << root->data << " " << " height = " << root->height << endl;
    in_order(root->right);
}

Node* min (Node* root)
{
    while(root && root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node* max(Node* root) 
{
    while (root->right != nullptr) 
    {
        root = root->right;
    }
    return root;
}

Node* delete_node(Node* root , int key)
{
    if(root == nullptr)
    {
        return root;
    }

    //Traverse down the tree until value matches key
    if(key < root->data)
    {
        root->left = delete_node(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = delete_node(root->right , key);
    }

    else
    {
        if (root->left != nullptr && root->right != nullptr) 
        {
            Node* temp = max(root->left);
            root->data = temp->data;
            root->left = delete_node(root->left, temp->data);
        } 
        else 
        {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
    }

    return root;
}

int main()
{
    Node* root = nullptr;
    root = insert(root , 5);
    root = insert(root , 3);
    root = insert(root , 10);
    root = insert(root , 2);
    root = insert(root , 4);
    root = insert(root , 7);
    root = insert(root , 11);
    root = insert(root , 1);
    root = insert(root , 6);
    root = insert(root , 9);
    root = insert(root , 12);
    root = insert(root , 8);

    root = delete_node(root , 5);



    in_order(root);

}



