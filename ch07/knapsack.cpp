#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>

using namespace std;

void shuffle_vector(vector<double>&);
template<class T>
void print_vector(vector<T>&, string);
void knapsack(vector<double>&, vector<double>&, set<int>&);
void print_set(set<int>& S);

const int N_ITEMS = 20;
const double MAX_WEIGHT = 11.4514;

int main()
{
    set<int> S;
    vector<double> values(N_ITEMS);
    vector<double> weights(N_ITEMS);
    iota(values.begin(), values.end(), 1);
    iota(weights.begin(), weights.end(), 1);
    shuffle_vector(values);
    shuffle_vector(weights);
    print_vector(values, "values :");
    print_vector(weights, "weights :");
    knapsack(values, weights, S);
    print_set(S);
}

void shuffle_vector(vector<double>& v)
{
    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(v.begin(), v.end(), engine);
}

template<class T>
void print_vector(vector<T>& v, string s)
{
    cout << s << endl;
    for (T t : v) cout << t << " ";
    cout << endl;
}

void knapsack(vector<double>& values, vector<double>& weights, set<int>& S)
{
    double value = 0;
    double weight = 0;
    int n_items = values.size();
    vector<int> rank_item(n_items);
    for (int i = 0; i < n_items; i++)
    {
        rank_item[i] = i;
    }
    // compute rank of items (value per weight)
    sort(rank_item.begin(), rank_item.end(), 
        [&](int i, int j)
        {
            return (values[i] / weights[i]) > (values[j] / weights[j]);
        }
    );
    print_vector(rank_item, "rank_item :");
    for (int i = 0; i < N_ITEMS; i++)
    {
        if (weight + weights[rank_item[i]] <= MAX_WEIGHT)
        {
            S.insert(rank_item[i]);
            value += values[rank_item[i]];
            weight += weights[rank_item[i]];
        }
    }
    int i_max_value;
    double max_value = -1;
    for (int i = 0; i < N_ITEMS; i++)
    {
        if (max_value < values[rank_item[i]] && weights[rank_item[i]] < MAX_WEIGHT)
        {
            i_max_value = rank_item[i];
            max_value = values[rank_item[i]];
        }
    }
    if (value < max_value)
    {
        S.clear();
        S.insert(i_max_value);
    }
}

void print_set(set<int>& S)
{
    cout << "knapsack :" << endl;
    for (auto itr = S.begin(); itr != S.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}