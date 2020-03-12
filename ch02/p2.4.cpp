#include <iostream>

using namespace std;

class Stack
{
public:
    unsigned int top;
    static const unsigned int MAX = 10;
    char data[MAX];

    Stack()
    {
        top = 0;
    }

    void pushdown(char c)
    {
        if (top < MAX) {
            data[top++] = c;
        }
        else
        {
            cerr << "ERROR: stack overflow." << endl;
        }
        return;
    }

    char popup()
    {
        char ret = '\0';
        if (top > 0)
        {
            ret = data[--top];
        }
        else
        {
            cout << "ERROR: stack is empty." << endl;
        }
        return ret;
    }

    void initialize()
    {
        top = 0;
        return;
    }

    bool empty()
    {
        if (top == 0) return true;
        return false;
    }
};

class Queue
{
public:
    Stack *Main, *Sub;
    Queue()
    {
        Main = new Stack();
        Sub = new Stack();
    }

    void enqueue(char c)
    {
        Main->pushdown(c);
        return;
    }

    char dequeue()
    {
        Stack* tmp;
        while (!Main->empty())
        {
            Sub->pushdown(Main->popup());
        }
        tmp = Main;
        Main = Sub;
        Sub = tmp;
        return Main->popup();
    }

    void initialize()
    {
        Main->initialize();
        Sub->initialize();
        return;
    }

    bool empty()
    {
        if (Main->empty()) return true;
        return false;
    }
};

int main()
{
    Queue Q;
    Q.enqueue('a'); Q.enqueue('b'); Q.enqueue('c'); Q.dequeue();
    Q.dequeue(); Q.enqueue('d'); Q.dequeue(); Q.enqueue('e');
    while (!Q.empty())
    {
        cout << Q.dequeue() << endl;
    }
    Q.enqueue('x');
    Q.initialize();
    Q.dequeue();
    return 0;
}

