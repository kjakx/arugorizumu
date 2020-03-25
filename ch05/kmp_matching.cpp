#include <iostream>
#include <vector>
#include <string>

using namespace std;

int kmp_matching(string text, string pattern, vector<int>& f);
void failure_function(vector<int>& f);

int main()
{
    string text = "string pattern matching";
    string pattern = "ing";
    int pos;
    vector<int> f;
    pos = kmp_matching(text, pattern, f);
    if (pos < 0) cout << "not found" << endl;
    else cout << "pattern found at " << pos << endl;
}

int kmp_matching(string text, string pattern, vector<int>& f)
{
    failure_function(f);
    int i_pattern = 0;
    int i_head = 0;
    int pos = -1;
    while (i_head < text.size() && i_pattern < pattern.size())
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