#include <iostream>
#include <vector>
#include <string>

using namespace std;

int kmp_matching(string& text, string& pattern, vector<int>& f);
void failure_function(string& pattern, vector<int>& f);

int main()
{
    string text = "ababdababccbdcabcadb";
    string pattern = "ababc";
    int pos;
    vector<int> f(pattern.size());
    pos = kmp_matching(text, pattern, f);
    if (pos < 0) cout << "not found" << endl;
    else cout << "pattern found at " << pos << endl;
}

int kmp_matching(string& text, string& pattern, vector<int>& f)
{
    failure_function(pattern, f);
    int i_pattern = 0;
    int i_head = 0;
    int pos = -1;
    while (i_pattern <= int(pattern.size() - 1) && i_head <= int(text.size() - 1))
    {
        if (i_pattern == -1 || pattern[i_pattern] == text[i_head])
        {
            i_pattern++;
            i_head++;
        }
        else
        {
            i_pattern = f[i_pattern];
        }
    }
    if (i_pattern == pattern.size())
    {
        pos = i_head - i_pattern;
    }
    return pos;
}

void failure_function(string& pattern, vector<int>& f)
{
    int i_pattern = -1;
    int i_head = 0;
    f[0] = -1;
    while(i_head < pattern.size() - 1)
    {
        if (i_pattern == -1 || pattern[i_pattern] == pattern[i_head])
        {
            i_pattern++;
            i_head++;
            f[i_head] = i_pattern;
        }
        else
        {
            i_pattern = f[i_pattern];
        }
    }
}