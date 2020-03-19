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
    int N = 100; // problem size
    int min_index;
    const int k = 3;
    vector<int> A(N);
    vector<int> B;
    int loop_count = 0;
    random_number(A, 1, 100);
    // ランダムな整数の配列Aから小さい順にk個取り出したい。
    // ソートしてから先頭k個とる方法では、O(nlogn)。
    // 最小値をループで取り出すのをk回繰り返す方法なら、O(n)。
    // 他にもバケツソート(O(n))、bit列(O(n))、優先度付きキューを使う方法(O(n))など。
    for (int i = 1; i <= k; i++)
    {
        min_index = 0;
        for (int j = 0; j < A.size(); j++)
        {
            loop_count++;
            if (A[min_index] > A[j])
            {
                min_index = j;
            }
        }
        B.push_back(A[min_index]);
        A[min_index] = 10000;   // 十分大きい値
    }
    cout << "### A ###" << endl;
    print_array(A);
    cout << "### B ###" << endl;
    print_array(B);
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