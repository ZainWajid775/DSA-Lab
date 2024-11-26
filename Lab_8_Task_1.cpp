#include <iostream>

using namespace std;

// License plate is stored as : 123

// Binary tree node structure
struct Node
{
    int data;
    Node* left;
    Node* right;
    
    //Constructor
    Node(int plate) : data(plate) , left(nullptr) , right(nullptr) {}
};

Node* insert(Node* root , int val)
{
    if(root == nullptr)
    {
        return new Node(val);
    }

    if(val > root->data)
    {
        root->right = insert(root->right , val);
    }
    else
    {
        root->left = insert(root->left , val);
    }

    return root;
}

bool search(Node* root , int val)
{
    if(root == nullptr)
    {
        return false;
    }

    if(val == root->data)
    {
        return true;
    }

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
    cout << root->data << " ";
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

Node* delete_node(Node* root , int key)
{
    if(root == nullptr)
    {
        return root;
    }

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
        if(root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = min(root->right);

        root->data = temp->data;

        root->right = delete_node(root->right , temp->data);
    }

    return root;

}

bool verify_plate(int plate)
{
    if(plate < 100 || plate > 999)
    {
        return false;
    }
    return true;
}

int main()
{
    Node* root = nullptr;
    bool exit = false;
    int option;

    while(!exit)
    {
        cout << "1. Add a car\n";
        cout << "2. Remove a car\n";
        cout << "3. Search for a car\n";
        cout << "4. Display all cars\n";
        cout << "5. Exit\n";
        cin >> option;
        cout << endl;

        switch (option)
        {
            case 1:
            {
                bool valid = false;
                int plate;
                while(!valid)
                {
                    cout << "Enter the license plate number : ";
                    cin >> plate;
                    valid = verify_plate(plate);
                    if(!valid)
                    {
                        cout << "Invalid license plate number\n";
                    }
                }

                cout << endl;
                root = insert(root , plate);

                cout << "Car added\n\n";
                break;
            }

            case 2:
            {
                int plate;
                bool valid = false;
                while(!valid)
                {
                    cout << "Enter the license plate number : ";
                    cin >> plate;
                    valid = verify_plate(plate);
                    if(!valid)
                    {
                        cout << "Invalid license plate number\n";
                    }
                }

                if(search(root , plate))
                {
                    cout << endl;
                    root = delete_node(root , plate);

                    cout << "Car removed\n\n";  
                }
                else
                {
                    cout << "Car not found\n\n";
                }

                break;
            }

            case 3:
            {
                int plate;
                bool valid = false;
                while(!valid)
                {
                    cout << "Enter the license plate number : ";
                    cin >> plate;
                    valid = verify_plate(plate);
                    if(!valid)
                    {
                        cout << "Invalid license plate number\n";
                    }
                }

                if(search(root , plate))
                {
                    cout << "Car found\n";
                }
                else
                {
                    cout << "Car not found\n";
                }
                cout << endl;
                break;
            }

            case 4:
            {
                if(root == nullptr)
                {
                    cout << "Lot empty\n";
                }
                else
                {
                    in_order(root);
                    cout << endl;
                }

                cout << endl;
                break;
            }
            
            case 5:
            {
                exit = true;
                break;
            }

            default:
            {
                cout << "Invalid option\n";
                break;
                cout << endl;
            }
        }
    }
}