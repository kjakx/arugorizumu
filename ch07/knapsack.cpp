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
    vector<int> item_rank(N_ITEMS);
    for (int i = 0; i < N_ITEMS; i++)
    {
        item_rank[i] = i;
    }
    // compute rank of items (value per weight)
    sort(item_rank.begin(), item_rank.end(), 
        [&](int i, int j)
        {
            return (values[i] / weights[i]) > (values[j] / weights[j]);
        }
    );
    print_vector(item_rank, "item_rank :");
    for (int i = 0; i < N_ITEMS; i++)
    {
        if (weight + weights[item_rank[i]] <= MAX_WEIGHT)
        {
            S.insert(item_rank[i]);
            value += values[item_rank[i]];
            weight += weights[item_rank[i]];
        }
    }
    int i_max_value;
    double max_value = -1;
    for (int i = 0; i < N_ITEMS; i++)
    {
        if (max_value < values[item_rank[i]] && weights[item_rank[i]] < MAX_WEIGHT)
        {
            i_max_value = item_rank[i];
            max_value = values[item_rank[i]];
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