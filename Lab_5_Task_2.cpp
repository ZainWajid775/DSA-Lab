#include <iostream>
using namespace std;

class queue
{
    private:

    char* arr;
    int size;
    int capacity;
    int front;
    int rear;

    public:

    queue(int s)
    {
        size = 0;
        capacity = s;
        front = 0;
        rear = -1;
        arr = new char[capacity];
    }

    bool is_full()
    {
        return (size == capacity);
    }

    bool is_empty()
    {
        return (size == 0);
    }

    void display()
    {
        if(is_empty())
        {
            cout << "Queue Empty\n";
            return;
        }
        else
        {
            cout << "Queue : " ;
            for(int i = 0 ; i < size ; i++)
            {
                cout << arr[i] << " " ;
            }
            cout << endl;
        }
    }

    void enqueue(const string &str)
    {
        if(is_full())
        {
            cout << "Queue Full\n";
            return;
        }
        else
        {
            for(char c : str)
            {
                arr[++rear] = c;
                size++;
            }
            cout << "Name Added\n";
            display();

        }
    }

    string dequeue()
    {
        if(is_empty())
        {
            return "Queue Empty\n";
        }
        else
        {
            string name;

            while(arr[front] != ' ')
            {
                name += arr[front++];
                size--;
            }
            return name;
        }
    }

    void clear()
    {
        cout << "Clearing queue\n";
        while(!is_empty())
        {
            arr[front++] = NULL;
            size--;
        }   
    }


};

int main()
{
    queue q(100);
    q.enqueue("zain wajid");
    cout << "Dequeue : " << q.dequeue() << endl;
    q.clear();
    q.display();
}