#include <iostream>

// using namespace std;

const int MAX = 10;
char data[MAX+1];
int next[MAX+1];
void create();
char access(int p, int i);
int newcell();
void insert(int p, int i, char x);
void del(int p, int i);
void initialize();
bool empty();

int main()
{
    int p;
    create();
    insert(next[0], 1, 'a'); insert(next[0], 1, 'c'); insert(next[0], 2, 'v');
    del(0, 1); insert(next[0], 2, 'a'); del(0, 3);
    p = next[0];
    while (p != 0)
    {
        std::cout << data[p] << std::endl;
        p = next[p];
    }
    std::cout << empty() << std::endl;
    initialize();
    std::cout << empty() << std::endl;
}

void create()
{
    for (int i = 0; i <= MAX; i++)
    {
        data[i] = '\0';
        next[i] = 0;
    }
    return;
}

char access(int p, int i)
{
    if (i > 1)
    {
        access(next[p], i - 1);
    }
    else
    {
        return data[p];
    }
}

int newcell()
{
    for (int i = 1; i <= MAX; i++)
    {
        if (data[i] == '\0') return i;        
    }
    std::cout << "ERROR: list is full." << std::endl;
    return 0;
}

void insert(int p, int i, char x)
{
    int q;
    if (i > 1)
    {
        insert(next[p], i - 1, x);
    }
    else
    {
        q = newcell();
        data[q] = x;
        next[q] = next[p];
        next[p] = q;
    }
}

void del(int p, int i)
{
    if (i > 1)
    {
        del(next[p], i - 1);
    }
    else
    {
        data[next[p]] = '\0';
        next[p] = next[next[p]];
    }
    return;
}

void initialize()
{
    create();
    return;
}

bool empty()
{
    if (next[0] == 0) return true;
    else return false;
}