#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

void shuffle_vector(vector<int>&);
int random_number(int, int);
void random_number(vector<int>&, int, int);
void quick_sort(vector<int>&, const int, const int);
int binary_search(vector<int>&, int key);
void print_array(vector<int>&);
void output_plotdata(const char* filename, vector<int>&);

int main()
{
    int N = 100; // problem size
    int key, key_index, pos;
    vector<int> v(N);
    random_number(v, 1, 100);
    quick_sort(v, 0, v.size() - 1);
    key_index = random_number(1, 100);
    key = v[key_index];
    pos = binary_search(v, key);
    if (pos < 0) cout << "key not found" << endl;
    else cout << "key found at " << pos << endl;
    cout << "### v ###" << endl;
    print_array(v);
    cout << "key = " << key << endl;
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

void random_number(vector<int>& v, int min, int max)
{
    random_device seed_gen;
    mt19937 engine(seed_gen());
    uniform_int_distribution<> rand(min+1, max+1);
    for (int i = 0; i < v.size(); i++) v[i] = rand(engine);
}


void quick_sort(vector<int>& v, const int left, const int right)
{
    int left_idx = left + 1, right_idx = right;
    int pivot_idx = left;
    int partition;
    if (left < right)
    {
        while (left_idx <= right_idx)
        {
            while (v[left_idx] < v[pivot_idx]) left_idx++;
            while (v[right_idx] > v[pivot_idx]) right_idx--;
            if (left_idx <= right_idx)
            {
                swap(v[left_idx++], v[right_idx--]);
            }
        }
        partition = right_idx;
        swap(v[pivot_idx], v[partition]);
        quick_sort(v, left, partition - 1);
        quick_sort(v, partition + 1, right);
    }
}
int binary_search(vector<int>& v, int key)
{
    int pos = -1;
    int left, right, mid;
    left = 0;
    right = v.size() - 1;
    mid = (right + left) / 2;
    while (left <= right)
    {
        if (v[mid] == key)
        {
            pos = mid;
            break;
        }
        else
        {
            if (v[mid] > key)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            mid = (right + left) / 2;
        }
    }
    return pos;
}

void print_array(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void output_plotdata(const char* filename, vector<int>& v)
{
    ofstream ofs(filename);
    for (int i = 0; i < v.size(); i++)
    {
        ofs << i+1 << " " << v[i] << endl;
    }
}