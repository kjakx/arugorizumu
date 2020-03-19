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
    int N = 33; // problem size
    vector<int> A(N+1), B(N+1), C(N+1), D(3*N);
    int a_itr = 0, b_itr = 0, c_itr = 0, d_itr = 0;
    int loop_count = 0;
    random_number(A, 1, 100);
    random_number(B, 1, 100);
    random_number(C, 1, 100);
    A[N] = 10000; B[N] = 10000; C[N] = 10000; // as sentinel
    quick_sort(A, 0, A.size() - 1);
    quick_sort(B, 0, B.size() - 1);
    quick_sort(C, 0, C.size() - 1);
    // 3つの配列をマージしてDに格納
    while (d_itr < 3*N)
    {
        if (A[a_itr] == min({A[a_itr], B[b_itr], C[c_itr]}))
        {
            D[d_itr++] = A[a_itr++];
        }
        else if (B[b_itr] == min({A[a_itr], B[b_itr], C[c_itr]}))
        {
            D[d_itr++] = B[b_itr++];
        }
        else    // C[c_itr] is minimum
        {
            D[d_itr++] = C[c_itr++];
        }
        loop_count++;
    }
    cout << "### A ###" << endl;
    print_array(A);
    cout << "### B ###" << endl;
    print_array(B);
    cout << "### C ###" << endl;
    print_array(C);
    cout << "### D ###" << endl;
    print_array(D);
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