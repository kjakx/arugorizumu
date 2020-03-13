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

class Queue : public List
{
public:

    Queue() : List() {}

    void enqueue(char c)
    {
        insert(1, 0, c);
    }

    char dequeue()
    {
        char ret;
        Node* prev = head;
        Node* current = head;
        if (current->next == NULL)
        {
            std::cout << "ERROR: queue is empty." << std::endl;
            return '\0';
        }
        current = current->next;
        while (current->next != NULL)
        {
            prev = prev->next;
            current = current->next;
        }
        ret = current->data;
        prev->next = NULL;
        delete current;
        //std::cout << ret << std::endl;
        return ret;
    }
};

int main()
{
    Queue* Q = new Queue();
    Q->enqueue('a'); Q->enqueue('b'); Q->enqueue('c'); Q->dequeue();
    Q->dequeue(); Q->enqueue('d'); Q->dequeue(); Q->enqueue('e');
    while (!Q->empty())
    {
        std::cout << Q->dequeue() << std::endl;
    }
    Q->enqueue('x');
    Q->initialize();
    Q->dequeue();
    return 0;
}