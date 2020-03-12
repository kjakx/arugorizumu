#include <iostream>

// using namespace std;
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

int main()
{
    List L;
    Node* p;
    L.create();
    L.insert(1, 0, 'a'); L.insert(1, 1, 'c'); L.insert(1, 2, 'v');
    L.del(1, 0); L.insert(1, 2, 'a'); L.del(1, 3);
    p = L.head;
    while (p->next != NULL)
    {
        std::cout << p->next->data << std::endl;
        p = p->next;
    }
    std::cout << L.empty() << std::endl;
    L.initialize();
    std::cout << L.empty() << std::endl;
}

