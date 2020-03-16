#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

void shuffle_vector(vector<int>&);
void quick_sort(vector<int>&, int, int);
void print_array(vector<int>&);
void output_plotdata(const char* filename, vector<int>&);
int swap_count = 0;
char filename[30];

int main()
{
    int N = 100; // problem size
    vector<int> v(N), v_work(N);
    for (int i = 1; i <= N; i++) v[i-1] = i;    // 1 ~ N までの整数を要素とする配列
    shuffle_vector(v);
    cout << "### before sorting ###" << endl;
    print_array(v);
    sprintf(filename, "./data/quick/%03d", ++swap_count);
    output_plotdata(filename, v);
    quick_sort(v, 0, v.size() - 1);
    cout << "### after sorting ###" << endl;
    print_array(v);
    return 0;
}

void shuffle_vector(vector<int>& v)
{
    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(v.begin(), v.end(), engine);
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
                sprintf(filename, "./data/quick/%03d", ++swap_count);
                output_plotdata(filename, v);
            }
        }
        partition = right_idx;
        swap(v[pivot_idx], v[partition]);
        sprintf(filename, "./data/quick/%03d", ++swap_count);
        output_plotdata(filename, v);
        quick_sort(v, left, partition - 1);
        quick_sort(v, partition + 1, right);
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

void output_plotdata(const char* filename, vector<int>& v)
{
    ofstream ofs(filename);
    for (int i = 0; i < v.size(); i++)
    {
        ofs << i+1 << " " << v[i] << endl;
    }
}