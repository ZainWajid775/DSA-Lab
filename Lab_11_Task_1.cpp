#include <iostream>
#include <list>

using namespace std;

struct Student
{
    int id;
    string name;
    string department;
    float gpa;
};

class Hash_Table
{
    public:

    int table_size;
    list<Student>* table;

    Hash_Table(int size)
    {
        table_size = size;
        table = new list<Student>[table_size];
    }

    int hash_function(int key)
    {
        return key % table_size;
    }

    void insert(Student s)
    {
        int index = hash_function(s.id);
        table[index].push_back(s);
    }

    void display()
    {
        for (int i = 0 ; i < table_size ; i++)
        {
            cout << i << " ";

            for (auto x : table[i])
            {
                cout << " --> " << x.id << " " << x.name << " " << x.department << " " << x.gpa;
            }
            cout << endl;
        }
    }


};

int main()
{
    Hash_Table ht(10);

    Student s1 = {101, "Ali", "CS", 3.5};
    Student s2 = {202, "Ahmed", "CS", 3.6};
    Student s3 = {303, "Asad", "CS", 3.7};
    Student s4 = {404, "Ahsan", "CS", 3.8};
    Student s5 = {404, "Aamir", "CS", 3.9};
    Student s6 = {404, "Aqeel", "CS", 4.0};
    Student s7 = {707, "Sanawar", "CS", 4.1};
    Student s8 = {808, "Aamir", "CS", 3.9};
    Student s9 = {909, "Aqeel", "CS", 4.0};
    Student s10 = {910, "Sanawar", "CS", 4.1};

    ht.insert(s1);
    ht.insert(s2);
    ht.insert(s3);
    ht.insert(s4);
    ht.insert(s5);
    ht.insert(s6);
    ht.insert(s7);
    ht.insert(s8);
    ht.insert(s9);
    ht.insert(s10);
    
    ht.display();

    return 0;
}