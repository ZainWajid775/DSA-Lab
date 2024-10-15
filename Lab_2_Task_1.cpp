#include <iostream>
using namespace std;

struct node
{
    int val;
    node* next;

    node (int value) : val(value) {}
};

class linked_list
{
    private:
    node* head;

    public:

    linked_list() : head(nullptr) {}

    void insertion(int value , int index)
    {
        //Empty list insertion
        if(head == nullptr)
        {
            node* new_node = new node(value);
            head = new_node;
        }

        //First index insertion
        else if (index == 0)
        {
            node* new_node = new node(value);
            new_node->next = head;
            head = new_node;
        }


        else
        {
            node* temp = head;

            //Traverse to index
            for (int i = 0 ; i < index - 1 ; i++)
            {
                temp = temp->next;

                //If index is greater than list size
                if(temp == nullptr)
                {
                    cout << "Invalid index\n";
                    return;
                }
            }

            node* new_node = new node(value);

            if(temp->next == nullptr)
            {
                temp->next = new_node;
            }
            else
            {
                new_node->next = temp->next;
                temp->next = new_node;
            }
            
        }
    }

    void deletetion(int index)
    {
        if(head == nullptr)
        {
            cout << "List empty\n";
        }
        else if(head->next == nullptr)
        {
            node* temp = head->next;
            delete temp;
            head = nullptr;
            cout << "Node at start deleted\n";
        }
        else if (index == 0)
        {
            node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node at start deleted\n";
        }
        else
        {
            node* temp = head;
            node* prev = nullptr;
            for(int i = 0 ; i < index ; i++)
            {
                prev = temp;
                temp = temp->next;
                if(temp == nullptr)
                {
                    cout << "Invalid index\n";
                    return;
                }
            }

            if(temp->next == nullptr)
            {
                prev->next = nullptr;
                delete temp;
                cout << "Node deleted at end index\n";
            }
            else
            {
                prev->next = temp->next;
                delete temp;  
                cout << "Node deleted at index : " << index << endl;
            }
        }
    }


    void print()
    {
        node* temp;
        int index = 0;
        for(temp = head; temp != nullptr; temp = temp->next)
        {
            cout << "Index : " << index << " Value : " << temp->val << endl;
            index++;
        }
    }
};

int main()  
{
    linked_list list;
    list.insertion(10,0);
    list.insertion(20,1);
    list.insertion(30,2);
    list.insertion(40,3);
    list.insertion(50,4);
    list.insertion(5,0);
    list.insertion(60,6);
    list.insertion(25,2);
    list.print();
    cout << endl;

    list.deletetion(0);
    list.print();
    cout << endl;

    list.deletetion(6);
    list.print();
    cout << endl;

    list.deletetion(2);
    list.print();


}