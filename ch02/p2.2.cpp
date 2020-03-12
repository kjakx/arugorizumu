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

