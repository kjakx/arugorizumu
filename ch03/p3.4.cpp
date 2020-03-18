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
int loop_count = 0;
char filename[30];

int main()
{
    int N = 3; // problem size
    int M = 10;
    vector<vector<int>> S(N, vector<int>(M, 0));
    vector<int> T(M);
    for (int i = 0; i < N; i++) random_number(S[i], 1, 100);
    for (int j = 0; j < M; j++)
    {
        T[j] = 0;
        for (int i = 0; i < N; i++)
        {
            T[j] += S[i][j];
        }
        loop_count++;
    }
    quick_sort(T, 0, T.size() - 1);
    cout << "### T ###" << endl;
    print_array(T);
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
    cout << "### v ###" << endl;
    print_array(v);
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