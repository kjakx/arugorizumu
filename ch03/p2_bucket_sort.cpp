#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

void shuffle_vector(vector<int>&);
void bucket_sort(vector<int>&);
void print_array(vector<int>&);
void output_plotdata(const char* filename, vector<int>&);
int swap_count = 0;
char filename[30];

int main()
{
    int N = 100; // problem size
    vector<int> v(N);
    for (int i = 1; i <= N; i++) v[i-1] = i % 10 + 1;    // 1 ~ 10 までの整数を要素とする配列
    shuffle_vector(v);
    cout << "### before sorting ###" << endl;
    print_array(v);
    sprintf(filename, "./data/bucket/%03d", ++swap_count);
    output_plotdata(filename, v);
    bucket_sort(v);
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

void bucket_sort(vector<int>& v)
{
    vector<int> bucket(11, 0);
    int j;
    for (int i = 0; i < v.size(); i++)
    {
        bucket[v[i]]++;
    }
    j = 0;
    for (int i = 0; i <= 10; i++)
    {
        while (bucket[i] > 0)
        {
            v[j++] = i;
            bucket[i]--;
            sprintf(filename, "./data/bucket/%03d", ++swap_count);
            output_plotdata(filename, v);
        }
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