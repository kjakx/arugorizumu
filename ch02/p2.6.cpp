#include <iostream>

using namespace std;

struct Node
{
    Node* next;
    char data;
};

class List
{
public:
    Node* head;

    List()
    {
        create();
    }

    void create()
    {
        head = newcell();
    }

    char access(int p, int i)
    {
        Node* current = head;
        int count = p + i - 1;
        while (count > 0)
        {
            if (current->next == NULL)
            {
                std::cout << "ERROR: can't access end of list." << std::endl;
                return '\0';
            }
            else
            {
                current = current->next;
            }
            count--;
        }
        return current->data;
    }

    Node* newcell()
    {
        Node* new_node = new Node();
        return new_node;
    }

    void insert(int p, int i, char x)
    {
        Node* q;
        Node* current = head;
        int count = p + i - 1;
        while (count > 0)
        {
            if (current->next == NULL)
            {
                std::cout << "ERROR: can't insert end of list." << std::endl;
                return;
            }
            else
            {
                current = current->next;
            }
            count--;
        }
        q = newcell();
        q->data = x;
        q->next = current->next;
        current->next = q;
    }

    void del(int p, int i)
    {
        Node* current = head;
        Node* prev = head;
        int count = p + i - 2;
        current = current->next;
        while (count > 0)
        {
            if (current->next == NULL)
            {
                std::cout << "ERROR: can't delete end of list." << std::endl;
                return;
            }
            else
            {
                current = current->next;
                prev = prev->next;
            }
            count--;
        }
        prev->next = current->next;
        delete current;
    }

    void initialize()
    {
        delete[] head->next;
        create();
        return;
    }

    bool empty()
    {
        if (head->next == NULL) return true;
        else return false;
    }
};

class Stack : public List
{
public:

    Stack() : List() {}

    void pushdown(char c)
    {
        insert(1, 0, c);
    }

    char popup()
    {
        char ret = '\0';
        if (head->next == NULL)
        {
            cout << "ERROR: stack is empty." << endl;
        }
        else
        {
            ret = head->next->data;
        }
        del(1, 0);
        return ret;
    }
};

int main()
{
    Stack *S = new Stack();
    S->pushdown('a'); S->pushdown('b'); S->pushdown('c'); S->popup();
    S->popup(); S->pushdown('d'); S->popup(); S->pushdown('e');
    while (!S->empty())
        cout << S->popup() << endl;
    cout << S->empty() << endl;
    S->pushdown('x');
    cout << S->empty() << endl;
    return 0;
}