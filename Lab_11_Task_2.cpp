#include <iostream>
#include <list>

using namespace std;

struct Node
{
    int key;
    int value;

    Node(int k , int v) : key(k) , value(v) {}
};

class Hash_Table
{
    public:

    int table_size;
    Node** table;

    Hash_Table(int size)
    {
        table_size = size;
        table = new Node*[table_size];
        for (int i = 0 ; i < table_size ; i++)
        {
            table[i] = nullptr;
        }
    }

    int hash_function(int key)
    {
        return key % table_size;
    }

    void insert(int key, int value) 
    {
        int index = hash_function(key);

        while (table[index] != nullptr && table[index]->key != key) 
        {
            index = (index + 1) % table_size;
        }

        if (table[index] == nullptr) 
        {
            table[index] = new Node(key, value);
        } 
        else 
        {
            table[index]->value = value;
        }
    }

       void display() 
       {

        for (int i = 0; i < table_size; i++) 
        {
            if (table[i] != nullptr) 
            {
                cout << i << " --> (" << table[i]->key << ", " << table[i]->value << ")" << endl;
            } 
            else 
            {
                cout << i << " --> Empty" << endl;
            }
        }
    }
};

int main()
{
    Hash_Table ht(10);

    ht.insert(10, 100);
    ht.insert(20, 200);
    ht.insert(31, 300);
    ht.insert(45, 400);
    ht.insert(55, 500);
    ht.insert(42, 600);
    ht.insert(56, 700);
    ht.insert(77, 800);
    ht.insert(89, 900);

    ht.display();
}