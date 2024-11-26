#include <iostream>

using namespace std;

// Binary tree node structure
struct Node
{
    int roll_no;
    int marks;
    Node* left;
    Node* right;
    
    //Constructor
    Node(int s_roll_no , int s_marks) : roll_no(s_roll_no) , marks(s_marks) , left(nullptr) , right(nullptr) {}
};

Node* insert(Node* root , int s_roll_no , int s_marks)
{
    if(root == nullptr)
    {
        return new Node(s_roll_no , s_marks);
    }

    if(s_roll_no > root->roll_no)
    {
        root->right = insert(root->right , s_roll_no , s_marks);
    }
    else
    {
        root->left = insert(root->left , s_roll_no , s_marks);
    }

    return root;
}

int search(Node* root , int s_roll_no)
{
    if(root == nullptr)
    {
        return -1;
    }

    if(s_roll_no == root->roll_no)
    {
        return root->marks;
    }

    if(s_roll_no < root->roll_no)
    {
        return search(root->left ,  s_roll_no);
    }
    else
    {
        return search(root->right , s_roll_no);
    }
}

void in_order(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    in_order(root->left);
    cout << root->roll_no << " ";
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

int main()
{
    Node* root = nullptr;
    bool exit = false;
    int option;

    while(!exit)
    {
        cout << "1. Add a student\n";
        cout << "2. Search for a student\n";
        cout << "3. Display all students\n";
        cout << "4. Exit\n";
        cin >> option;
        cout << endl;

        switch (option)
        {
            case 1:
            {
                bool valid = false;
                int s_roll_no , s_marks;

                while(!valid)
                {
                    cout << "Enter the student's roll number : ";
                    cin >> s_roll_no;
                    cout << endl;
                    valid = (s_roll_no > 0);
                    if(!valid)
                    {
                        cout << "Invalid roll number\n";
                    }

                    cout << "Enter the student's marks : ";
                    cin >> s_marks;
                    cout << endl;
                    valid = (s_marks > -1);
                    if(!valid)
                    {
                        cout << "Invalid marks\n";
                    }
                }

                cout << endl;
                root = insert(root , s_roll_no , s_marks);

                cout << "Student added\n\n";
                break;
            }

            case 2:
            {
                int s_roll_no;
                bool valid = false;
                while(!valid)
                {
                    cout << "Enter the student's roll number : ";
                    cin >> s_roll_no;
                    valid = (s_roll_no > 0);
                    if(!valid)
                    {
                        cout << "Invalid roll number\n";
                    }
                }

                int temp = search(root , s_roll_no);

                if(temp > -1)
                {
                    cout << "Student found\n";
                    cout << "Students Marks : " << temp << endl << endl;
                }
                else
                {
                    cout << "Student not found\n\n";
                }

                break;
            }

            case 3:
            {
                if(root == nullptr)
                {
                    cout << "No students in database\n";
                }
                else
                {
                    in_order(root);
                    cout << endl;
                }

                cout << endl;
                break;
            }
            
            case 4:
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