#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void g(string& pattern, vector<int>& g);
void h(string& pattern, vector<int>& h, vector<int>& f);

int main()
{
    return 0;
}

void g(string& pattern, vector<int>& g)
{
    for (int c = 0; c <= 255; c++)
    {
        g[c] = pattern.size() - 1;
    }
    for (int k = 0; k < pattern.size(); k++)
    {
        g[pattern[k]] = pattern.size() - 1 - k;
    }
}

void h(string& pattern, vector<int>& h, vector<int>& f)
{
    int i, j;
    for (i = 0; i < pattern.size(); i++)
    {
        h[i] = 2 * (pattern.size() - 1) - 1;
    }
    i = pattern.size() - 1;
    j = pattern.size();
    f[pattern.size() - 1] = pattern.size();
    while (i >= 0)
    {
        if (j == pattern.size() || pattern[i] == pattern[j])
        {
            i = i - 1;
            j = j - 1;
            f[i] = j;
        }
        else
        {
            h[j] = min(h[j], int(pattern.size()) - 1 - i);
            j = f[j];
        }
    }
    for (i = 0; i < pattern.size(); i++)
    {
        h[i] = min(h[j], int(pattern.size()) - j - 1);
        if (i >= j)
        {
            j = f[j];
        }
    }
}