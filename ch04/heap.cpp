#include <iostream>
#include <vector>

using namespace std;

class Heap
{
public:
    vector<int> data;

    Heap()
    {
        data.push_back(-1); // dummy data
    }

    void down_heap(int key, int range)
    {
        int down = data[key];
        int down_index = key;
        int child_index = key * 2;
        while (child_index <= range)
        {
            // if current node has two children, take a index of smaller child
            if (child_index < range && data[child_index] > data[child_index + 1])
            {
                child_index = child_index + 1;
            }
            if (down > data[child_index])
            {
                data[down_index] = data[child_index];
                down_index = child_index;
                child_index = child_index * 2;
            }
            else
            {
                data[down_index] = down;
                break;
            }
        }
    }

    void delete_min()
    {
        data[1] = data[data.size() - 1];
        data.pop_back();
        down_heap(1, data.size() - 1);
    }

    void up_heap(int n)
    {
        int up = data[n];
        int up_index = n;
        int parent_index = n / 2;
        while (parent_index >= 0)
        {
            if (data[parent_index] >= up)
            {
                data[up_index] = data[parent_index];
                up_index = parent_index;
                parent_index = parent_index / 2;
            }
            else
            {
                data[up_index] = up;
                break;
            }
        }
    }

    void insert(int x)
    {
        data.push_back(x);
        up_heap(data.size() - 1);
    }

    void print_heap()
    {
        for (int i = 1; i < data.size(); i++)
        {
            cout << data[i] << endl;
        }
    }
};

int main()
{
    Heap h;
    int S[11] = {59, 38, 7, 42, 16, 81, 4, 32, 95, 18, 25};
    for (int i = 0; i < 11; i++)
    {
        h.insert(S[i]);
    }
    h.print_heap();
    cout << "---" << endl;
    h.delete_min();
    h.print_heap();
    cout << "---" << endl;
    h.insert(9);
    h.print_heap();
    cout << "---" << endl;
}