#include <iostream>

using namespace std;

void pushdown(char*, char);
char popup(char*);
void initialize(char* S);
bool empty(char* S);
unsigned int top = 0;
unsigned int MAX = 10;

int main()
{
    char S[MAX];
    pushdown(S, 'a'); pushdown(S, 'b'); pushdown(S, 'c'); popup(S);
    popup(S); pushdown(S, 'd'); popup(S); pushdown(S, 'e');
    for (int i = top - 1; i >= 0; i--)
        cout << popup(S) << endl;
    cout << empty(S) << endl;
    return 0;
}

void pushdown(char* S, char c)
{
    if (top < MAX) {
        S[top++] = c;
    }
    else
    {
        cerr << "ERROR: stack overflow." << endl;
    }
    return;
}

char popup(char* S)
{
    char ret = '\0';
    if (top > 0)
    {
        ret = S[--top];
    }
    else
    {
        cout << "ERROR: stack is empty." << endl;
    }
    return ret;
}

void initialize(char* S)
{
    top = 0;
    return;
}

bool empty(char* S)
{
    if (top == 0) return true;
    return false;
}