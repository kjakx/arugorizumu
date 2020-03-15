#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

void shuffle_vector(vector<int>&);
void insertion_sort(vector<int>&);
void print_array(vector<int>&);
void output_plotdata(const char* filename, vector<int>&);

int main()
{
    int N = 100; // problem size
    vector<int> v(N);
    for (int i = 1; i <= N; i++) v[i-1] = i;    // 1 ~ N までの整数を要素とする配列
    shuffle_vector(v);
    cout << "### before sorting ###" << endl;
    print_array(v);
    insertion_sort(v);
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

void insertion_sort(vector<int>& v)
{
    int min_index;
    char filename[30];
    int i;
    for (i = 1; i < v.size(); i++)
    {
        sprintf(filename, "./data/insertion/%03d", i);
        output_plotdata(filename, v);
        min_index = i;
        for (int j = i; j >= 1; j--)
        {
            if (v[j] < v[j-1]) swap(v[j], v[j-1]);
        }
    }
    sprintf(filename, "./data/insertion/%03d", i);
    output_plotdata(filename, v);
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