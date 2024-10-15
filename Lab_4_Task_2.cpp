#include <iostream>
using namespace std;

class stack
{
    private:
    char* arr;
    int size;
    int top;

    public:
    stack (int capacity)
    {
        size = capacity;
        top = -1;
        arr = new char [size];
    } 

    bool is_full()
    {
        if(top - 1 == size)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool is_empty()
    {
        if(top == -1)
        {
            return 1;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        if(is_empty())
        {
            cout << "Stack Underflow\n";
        }
        else
        {
            for(int i = 0 ; i != top + 1 ; i++)
            {
                cout << "Index : " << size - i << " Data : " << arr[i] << endl;
            }
        }
    }

    void push(char val)
    {
        if(is_full())
        {
            throw std::overflow_error("Stack Overflow");
        }
        else
        {
            arr[++top] = val;
        }
    }

    char pop()
    {
        if(!is_empty())
        {
            return arr[top--];
        }
        else
        {
            cout << "Stack Underflow\n";
            return 'a';
        }
    }

    char peek()
    {
        if(!is_empty())
        {
            return arr[top];
        }
        else
        {
            cout << "Stack Underflow\n";
            return 'a';
        }
    }

};

string reverse_string(stack& s , const string& str)
{
    cout << "Input String : " << str << endl;
    string reverse;

    for(char c: str )
    {
        s.push(c);
    }

    while(!s.is_empty())
    {
        reverse = reverse + s.pop();
    }

    return reverse;
}

int main()
{
    stack temp(10);
    cout << reverse_string(temp , "Hello");

}

