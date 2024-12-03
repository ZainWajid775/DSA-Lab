#include <iostream>
using namespace std;

struct Node
{
    int sku;
    Node* left;
    Node* right;
    int height;

    Node(int SKU) : sku(SKU), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* n)
{
    if(n == nullptr)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}

Node* retrieve(Node* root , int sku)
{
    if(!root)
    {
        return nullptr;
    }

    if(sku < root->sku)
    {
        return retrieve(root->left , sku);
    }
    else if(sku > root->sku)
    {
        return retrieve(root->right , sku);
    }
    else
    {
        return root;
    }
}

Node* right_rotate(Node* node)
{
    Node* left = node->left;
    Node* right = left->right;

    left->right = node;
    node->left = right;

    node->height = 1 + max(height(node->left), height(node->right));
    left->height = 1 + max(height(left->left), height(left->right));

    return left;
}

Node* left_rotate(Node* node)
{
    Node* right = node->right;
    Node* left = right->left;

    right->left = node;
    node->right = left;

    node->height = 1 + max(height(node->left), height(node->right));
    right->height = 1 + max(height(right->left), height(right->right));

    return right;
}

int get_balance(Node* n)
{
    if(n == nullptr)
    {
        return 0;
    }
    else
    {
        return height(n->left) - height(n->right);
    }
}

Node* insert(Node* node , int key)
{
    if(node == nullptr)
    {
        return new Node(key);
    }

    if(key < node->sku)
    {
        node->left = insert(node->left , key);
    }
    else if(key > node->sku)
    {
        node->right = insert(node->right , key);
    }
    else
    {
        return node;
    }

    node->height = 1 + max(height(node->left) , height(node->right));

    int balance = get_balance(node);

    // Left left
    if(balance > 1 && key < node->left->sku)
    {
        return right_rotate(node);
    }

    // Right right
    if(balance < -1 && key > node->right->sku)
    {
        return left_rotate(node);
    }

    // Left right case
    if(balance > 1 && key > node->left->sku)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right left case
    if(balance < -1 && key < node->right->sku)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void in_order(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    in_order(root->left);
    cout << root->sku << " ";
    in_order(root->right);
}

Node* min(Node* node)
{
    Node* current = node;
    
    while(current->left != nullptr)
    {
        current = current->left;
    }

    return current;
}

Node* delete_node(Node* root , int sku)
{
    if(!root)
    {
        return root;
    }

    if(sku < root->sku)
    {
        root->left = delete_node(root->left, sku);
    }
    else if (sku > root->sku)
    {
        root->right = delete_node(root->right, sku);
    }

    else
    {
        if((root->left == nullptr) || (root->right == nullptr))
        {
            Node* temp = root->left ? root->left : root->right;

            if(temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
            {
                *root = *temp;
            }
            delete temp;
        }
        else
        {
            Node* temp = min(root->right);
            root->sku = temp->sku;
            root->right = delete_node(root->right, temp->sku);
        }
    }

    if(!root)
    {
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = get_balance(root);

    if(balance > 1 && get_balance(root->left) >= 0)
    {
        return right_rotate(root);
    }
    if(balance < -1 && get_balance(root->right) <= 0)
    {
        return left_rotate(root);
    }
    if(balance > 1 && get_balance(root->left) < 0)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance < -1 && get_balance(root->right) > 0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;

}

int main()
{
    Node* root = nullptr;
    root = insert(root , 10);
    root = insert(root , 20);
    root = insert(root , 30);
    root = insert(root , 40);
    root = insert(root , 50);
    root = insert(root , 25);
    in_order(root);
    cout << endl;

    Node* temp = retrieve(root , 10);
    if(temp)
    {
        cout << "Found " << temp->sku << endl;
    }
    else
    {
        cout << "Not Found\n";
    }

    root = delete_node(root , 25);

    in_order(root);

    return 0;
}
