#include <iostream>

using namespace std;

class Queue
{
public:
    unsigned int head, tail;
    unsigned int q_size;
    static const unsigned int MAX = 10;
    char data[MAX+1];

    Queue()
    {
        head = 0; tail = 0;
        q_size = 0;
        data[0] = '\0';
    }

    void enqueue(char c)
    {
        if (q_size < MAX)
        {
            q_size++;
            tail = tail % MAX + 1;
            data[tail] = c;
        }
        else
        {
            cout << "ERROR: queue is full." << endl;
        }
        return;
    }

    char dequeue()
    {
        char ret = '\0';
        if (q_size > 0)
        {
            q_size--;
            head = head % MAX + 1;
            ret = data[head];
        }
        else
        {
            cout << "ERROR: queue is empty" << endl;
        }
        return ret;
    }

    void initialize()
    {
        q_size = 0; head = 0; tail = 0;
        return;
    }

    bool empty()
    {
        if (q_size == 0) return true;
        return false;
    }
};

class Stack
{
public:
    Queue *Top, *Sub;
    Queue *tmp;

    Stack()
    {
        Top = new Queue;
        Sub = new Queue;
    }

    void pushdown(char c)
    {
        if (!Top->empty()) {
            Sub->enqueue(Top->dequeue());
        }
        Top->enqueue(c);
        return;
    }

    char popup()
    {
        char ret = '\0';
        if (!Top->empty())
        {
            ret = Top->dequeue();
        }
        else
        {
            cout << "ERROR: stack is empty." << endl;
        }
        while(Sub->q_size > 1)
        {
            Top->enqueue(Sub->dequeue());
        }
        tmp = Sub;
        Sub = Top;
        Top = tmp;
        return ret;
    }

    char peek()
    {
        return Top->data[Top->tail];
    }

    void initialize()
    {
        Top->initialize();
        Sub->initialize();
    }

    bool empty()
    {
        if (Top->empty()) return true;
        return false;
    }
};

int main()
{
    Stack S;
    S.pushdown('a'); S.pushdown('b'); S.pushdown('c'); S.popup();
    S.popup(); S.pushdown('d'); S.popup(); S.pushdown('e');
    while (!S.empty())
        cout << S.popup() << endl;
    cout << S.empty() << endl;
    S.pushdown('x');
    cout << S.empty() << endl;
    return 0;
}