#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>

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
        int current = data[key];
        int current_index = key;
        int child_index = key * 2;
        while (child_index <= range)
        {
            // if current node has two children, take a index of smaller child
            if (child_index < range && data[child_index] > data[child_index + 1])
            {
                child_index = child_index + 1;
            }
            if (current > data[child_index])
            {
                data[current_index] = data[child_index];
                current_index = child_index;
                child_index = child_index * 2;
            }
            else
            {
                data[current_index] = current;
                break;
            }
        }
        // current is a leaf
        if (child_index > range) data[current_index] = current;
    }

    void delete_min()
    {
        data[1] = data[data.size() - 1];
        data.pop_back();
        down_heap(1, data.size() - 1);
    }

    void up_heap(int n)
    {
        int current = data[n];
        int current_index = n;
        int parent_index = n / 2;
        while (parent_index >= 0)
        {
            if (data[parent_index] >= current)
            {
                data[current_index] = data[parent_index];
                current_index = parent_index;
                parent_index = parent_index / 2;
            }
            else
            {
                data[current_index] = current;
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

void shuffle_vector(vector<int>&);
void heap_sort(Heap&, vector<int>&);
void output_plotdata(const char* filename, vector<int>&);
void print_array(vector<int>&);
char filename[30];
const int N = 100;  // problem size
int plot_count = 0;

int main()
{
    Heap h;
    vector<int> S(N);
    vector<int> sorted;
    for (int i = 0; i < N; i++)
    {
        S[i] = i+1;
    }
    shuffle_vector(S);
    sprintf(filename, "./data/heap/%03d", ++plot_count);
    output_plotdata(filename, S);
    vector<int> plot_vec(N, 0);
    for (int i = 0; i < N; i++)
    {
        h.insert(S[i]);
        //--- for plotting (unnecessary for making heap) ---
        for (int j = 0; j < i + 1; j++)
        {
            plot_vec[j] = h.data[j+1];
        }
        for (int k = i + 1; k < N; k++)
        {
            plot_vec[k] = S[k];
        }
        sprintf(filename, "./data/heap/%03d", ++plot_count);
        output_plotdata(filename, plot_vec);
        //------
    }
    //h.print_heap();
    //cout << "### before sorting ###" << endl;
    //print_array(S);
    //cout << "### heap ###" << endl;
    //h.print_heap();
    heap_sort(h, sorted);
    cout << "### after sorting ###" << endl;
    print_array(sorted);
    return 0;
}

void shuffle_vector(vector<int>& v)
{
    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(v.begin(), v.end(), engine);
}

int random_number(int min, int max)
{
    int r;
    random_device seed_gen;
    mt19937 engine(seed_gen());
    uniform_int_distribution<> rand(min, max);
    r = rand(engine);
    return r;
}

// O(height of heap (logn)) * O(number of element(n)) = O(nlogn)
void heap_sort(Heap& h, vector<int>& v)
{
    int min;
    vector<int> plot_vec(N, 0);
    for (int i = 1; i <= N; i++)
    {
        min = h.data[1];
        v.push_back(min);
        //--- for plotting (unnecessary for sorting algorithm) ---
        for (int j = 0; j < i; j++)
        {
            plot_vec[j] = v[j];
        }
        h.delete_min();
        for (int k = i; k < N; k++)
        {
            plot_vec[k] = h.data[k - i + 1];
        }
        sprintf(filename, "./data/heap/%03d", ++plot_count);
        output_plotdata(filename, plot_vec);
        //------
    }
}

void output_plotdata(const char* filename, vector<int>& v)
{
    ofstream ofs(filename);
    for (int i = 0; i < v.size(); i++)
    {
        ofs << i+1 << " " << v[i] << endl;
    }
}

void print_array(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}