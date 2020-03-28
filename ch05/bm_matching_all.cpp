#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void g_function(string& pattern, vector<int>& g);
void h_function(string& pattern, vector<int>& h, vector<int>& f);
void bm_matching(string& text, string& pattern, vector<int>& f, vector<int>& g, vector<int>& h, vector<int>& matches);
void print_vector(vector<int>& v);

int main()
{
    string text = "ababdababccbdcababcadb";
    string pattern = "ababc";
    vector<int> f(pattern.size()), g(256), h(pattern.size());
    vector<int> matches;
    bm_matching(text, pattern, f, g, h, matches);
    print_vector(matches);
    return 0;
}

void g_function(string& pattern, vector<int>& g)
{
    for (int c = 0; c <= 255; c++)
    {
        g[c] = pattern.size() - 1;
    }
    for (int k = 0; k < pattern.size(); k++)
    {
        g[pattern[k]] = int(pattern.size()) - 1 - k;
    }
}

void h_function(string& pattern, vector<int>& h, vector<int>& f)
{
    int i, j;
    for (i = 0; i < pattern.size(); i++)
    {
        h[i] = 2 * int(pattern.size() - 1) - i;
    }
    i = pattern.size() - 1;
    j = pattern.size();
    f[pattern.size() - 1] = pattern.size();
    while (i >= 0)
    {
        if (j == pattern.size() || pattern[i] == pattern[j])
        {
            i--;
            j--;
            if (i < 0) break;
            else f[i] = j;
        }
        else
        {
            h[j] = min(h[j], int(pattern.size()) - 1 - i);
            j = f[j];
        }
    }
    for (i = 0; i < pattern.size(); i++)
    {
        h[i] = min(h[i], int(pattern.size()) - 1 + j - i);
        if (i >= j)
        {
            j = f[j];
        }
    }
}

void bm_matching(string& text, string& pattern, vector<int>& f, vector<int>& g, vector<int>& h, vector<int>& matches)
{
    g_function(pattern, g);
    h_function(pattern, h, f);
    int i = pattern.size() - 1;
    int j = pattern.size() - 1;
    while (0 <= j && j < int(text.size()))
    {
        if (pattern[i] == text[j])
        {
            i--;
            j--;
            if (i < 0)
            {
                matches.push_back(j + 1);
                i = pattern.size() - 1;
                j += pattern.size() + 1;
            }
        }
        else
        {
            j = j + max(g[text[j]], h[i]);
            i = pattern.size() - 1;
        }
    }
}

void print_vector(vector<int>& v)
{
    for (int v_elem : v) cout << v_elem << endl;
}