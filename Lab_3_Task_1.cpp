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

    void insert_at_end(int val)
    {
        node* new_node = new node(val);
        
        if(tail != nullptr)
        {   
            //When list is not empty
            tail->next = new_node;
            new_node->prev = tail;
        }
        else
        {
            head = new_node;
        }

        tail = new_node;
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
};

int main()
{
    doubly_linked_list list;
    int user_value;
    int count = 0;

    while(user_value != -1)
    {
        cout << "Index : " << count << " Enter value : ";
        cin >> user_value;
        count ++;
        if(user_value == -1)
        {
            cout <<endl;
            list.display();
        }
        else
        {
            list.insert_at_end(user_value);
        }
    }


}