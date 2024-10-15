#include <iostream>
using namespace std;

struct node
{
    int val;
    node* next;
    node* prev;

    node(int value) : val(value) , next(nullptr) , prev(nullptr) {}
};

class doubly_linked_list
{
    private:
    node* head;
    node* tail;

    public:

    doubly_linked_list() : head(nullptr) , tail(nullptr) {}

    void insert_at_start(int val)
    {
        node* new_node = new node(val);
        
        if(head != nullptr)
        {   
            //When list is not empty
            head->prev = new_node;
            new_node->next = head;
        }
        else
        {
            tail = new_node;
        }
        
        head = new_node;
    }

    void display()
    {
        node* temp = head;
        int count = 0;
        
        while(temp != nullptr)
        {
            cout << "Index : " << count << " Value : " << temp->val << endl;
            count++;
            temp = temp->next;
        }
    }

    bool deletion(int value)
    {
        node* temp = head;
        node* prev;
        bool found = false;

        while(!found)
        {
            if(temp-> val == value)
            {
                found = true;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        
        if(!found)
        {
            return false;
        }
        else
        {
            //First node deletion
            if(prev == nullptr)
            {
                prev = temp;
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
            //Last node deletion
            else if(temp->next == nullptr)
            {
                tail = prev;
                tail->next = nullptr;
                delete temp;
            }   
            else
            {
                prev->next = temp->next;
                temp->prev = prev;
                delete temp;
            }

            return true;
        }

    }
};


int main()
{
    doubly_linked_list list;
    int user_value;
    int count = 0;
    int menu;

    while(user_value != -1)
    {
        cout << "1. Insert value\n"; 
        cout << "2. Delete value\n";
        cout << "Type here : ";
        cin >> menu;

        switch(menu)
        {
            case 1:
            {
                cout << "\nEnter value : ";
                cin >> user_value;
                cout << endl;
                list.insert_at_start(user_value); 
                break; 
            }

            case 2:
            {
                cout << "\nEnter value to delete : ";
                cin >> user_value;
                cout << endl;
                if(list.deletion(user_value))
                {
                    cout << "Node deleted\n";
                    cout << "Updated List\n";
                    list.display();
                    cout <<endl;
                }
                else
                {
                    cout << "Value not found\n";
                }

                break;
            }

            default:
            {
                cout << "\nInvalid input\n\n";
                break;
            }
            


        }
    }

 


}