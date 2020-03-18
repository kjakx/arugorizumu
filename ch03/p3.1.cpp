#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

void shuffle_vector(vector<int>&);
void random_number(vector<int>&, int, int);
void quick_sort(vector<int>&, int, int);
void print_array(vector<int>&);
void output_plotdata(const char* filename, vector<int>&);
int swap_count = 0;
char filename[30];

int main()
{
    int N = 50; // problem size
    vector<int> A(N), B(N), C;
    int a_itr = 0, b_itr = 0;
    int loop_count = 0;
    random_number(A, 1, 100);
    random_number(B, 1, 100);
    quick_sort(A, 0, A.size() - 1); // O(nlogn)
    quick_sort(B, 0, B.size() - 1); // O(nlogn)
    // 最悪計算量：O(n)
    while (!(a_itr > A.size() - 1 || b_itr > B.size() - 1))
    {
        if (A[a_itr] == B[b_itr])
        {
            C.push_back(A[a_itr]);
            a_itr++; b_itr++;
        }
        else
        {
            if (A[a_itr] > B[b_itr])
            {
                b_itr++;
            }
            else
            {
                a_itr++;
            }
        }
        loop_count++;
    }
    cout << "### A ###" << endl;
    print_array(A);
    cout << "### B ###" << endl;
    print_array(B);
    cout << "### C ###" << endl;
    print_array(C);
    cout << "loop_count : " << loop_count << endl;
    return 0;
}

void shuffle_vector(vector<int>& v)
{
    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(v.begin(), v.end(), engine);
}

void random_number(vector<int>& v, int min, int max)
{
    random_device seed_gen;
    mt19937 engine(seed_gen());
    uniform_int_distribution<> rand(min+1, max+1);
    for (int i = 0; i < v.size() - 1; i++) v[i] = rand(engine);
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