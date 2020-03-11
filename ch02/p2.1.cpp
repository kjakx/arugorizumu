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

int main()
{
    Stack *S = new Stack();
    S->pushdown('a'); S->pushdown('b'); S->pushdown('c'); S->popup();
    S->popup(); S->pushdown('d'); S->popup(); S->pushdown('e');
    for (int i = S->top - 1; i >= 0; i--)
        cout << S->popup() << endl;
    cout << S->empty() << endl;
    S->pushdown('x');
    cout << S->empty() << endl;
    return 0;
}