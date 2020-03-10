#include <iostream>

using namespace std;

void enqueue(char*, char);
char dequeue(char*);
void initialize(char*);
bool empty(char*);
unsigned int head = 0, tail = 0;
unsigned int q_size = 0;
unsigned int MAX = 10;

int main()
{
    char Q[MAX+1]; 
    Q[0] = '\0';
    enqueue(Q, 'a'); enqueue(Q, 'b'); enqueue(Q, 'c'); dequeue(Q);
    dequeue(Q); enqueue(Q, 'd'); dequeue(Q); enqueue(Q, 'e');
    while (!empty(Q))
    {
        cout << dequeue(Q) << endl;
    }
    enqueue(Q, 'x');
    initialize(Q);
    dequeue(Q);
    return 0;
}

void enqueue(char* Q, char c)
{
    if (q_size < MAX)
    {
        q_size++;
        tail = tail % MAX + 1;
        Q[tail] = c;
    }
    else
    {
        cout << "ERROR: queue is full." << endl;
    }
    return;
}

char dequeue(char* Q)
{
    char ret = '\0';
    if (q_size > 0)
    {
        q_size--;
        head = head % MAX + 1;
        ret = Q[head];
    }
    else
    {
        cout << "ERROR: queue is empty" << endl;
    }
    return ret;
}

void initialize(char* Q)
{
    q_size = 0; head = 0; tail = 0;
    return;
}

bool empty(char* Q)
{
    if (q_size == 0) return true;
    return false;
}