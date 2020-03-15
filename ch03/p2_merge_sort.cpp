#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

void shuffle_vector(vector<int>&);
void merge_sort(vector<int>&, vector<int>&, int, int);
void print_array(vector<int>&);
void output_plotdata(const char* filename, vector<int>&);
int merge_count = 0;
char filename[30];

int main()
{
    int N = 100; // problem size
    vector<int> v(N), v_work(N);
    for (int i = 1; i <= N; i++) v[i-1] = i;    // 1 ~ N までの整数を要素とする配列
    shuffle_vector(v);
    cout << "### before sorting ###" << endl;
    print_array(v);
    sprintf(filename, "./data/merge/%03d", ++merge_count);
    output_plotdata(filename, v);
    merge_sort(v, v_work, 0, v.size() - 1);
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

void merge_sort(vector<int>& v, vector<int>& v_work, const int left, const int right)
{
    int half = (right - left) / 2 + left;
    if (left < right)
    {
        merge_sort(v, v_work, left, half);
        merge_sort(v, v_work, half + 1, right);
        int left_itr = left, right_itr = half + 1;
        //--- merge処理 ---
        for (int i = left; i <= right; i++)
        {
            // 左半分の配列が空
            if (left_itr == half + 1) v_work[i] = v[right_itr++];
            // 右半分の配列が空なら、左半分の配列の要素を
            else if (right_itr == right + 1) v_work[i] = v[left_itr++];
            // どちらにも要素が残っている場合、それぞれの先頭要素の小さいほうをv_workに格納する
            else
            {
                if (v[left_itr] < v[right_itr])
                {
                    v_work[i] = v[left_itr++];
                }
                else
                {
                    v_work[i] = v[right_itr++];
                }
            }
        }
        // ソート済み作業配列をもとの配列にコピー
        for (int j = left; j <= right; j++)
        {
            v[j] = v_work[j];
        }
        sprintf(filename, "./data/merge/%03d", ++merge_count);
        output_plotdata(filename, v);
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