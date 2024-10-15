#include <iostream>
using namespace std;

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

    void remove_duplicates()
    {
        node* temp_1 = head;
        
        while(temp_1 != nullptr)
        {
            node* temp_2 = head->next;

            while(temp_2 != nullptr)
            {
                if(temp_2->val == temp_1->val && temp_1 != temp_2)
                {
                    node* dupe = temp_2;
                    temp_2 = temp_2->next;

                    if(dupe->prev != nullptr)
                    {
                        dupe->prev->next = temp_2;
                    }
                    if(dupe->next != nullptr)
                    {
                        dupe->next->prev = dupe->prev;
                    }
                    delete dupe;

                } 
                else
                {
                    temp_2 = temp_2->next;
                }
            }

            temp_1 = temp_1->next;
        }
    }

};

int main()
{
    doubly_linked_list list;

    list.insert_at_end(1);
    list.insert_at_end(2);
    list.insert_at_end(3);
    list.insert_at_end(3);
    list.insert_at_end(4);
    list.display();
    cout << endl;

    list.remove_duplicates();
    cout << "Removing duplicates\n\n";

    list.display();




}