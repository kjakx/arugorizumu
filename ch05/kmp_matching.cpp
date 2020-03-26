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

// kmp matching is a pattern matching method
// that uses failure function which tells
// what to do next when the matching failed.
// time complexity: O(n+m) where n is the length of a text and m is the length of a pattern
int kmp_matching(string& text, string& pattern, vector<int>& f)
{
    failure_function(pattern, f);
    int i_pattern = 0;
    int i_head = 0;
    int pos = -1;
    // compared unsigned int, negative int is casted to corresponding int.
    // to prevent it, size() is casted to int before it is compared with negative int.
    while (i_pattern <= int(pattern.size() - 1) && i_head <= int(text.size() - 1))
    {
        // i_pattern -1 means that the matching between the first character of pattern and text was failed.
        if (i_pattern == -1 || pattern[i_pattern] == text[i_head])
        {
            i_pattern++;
            i_head++;
        }
        else
        {
            // f[i] tells which charater in pattern to be compared to text[i_head] next
            // when comparison between text[i_head] and pattern[i] was failed. 
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
    // comparing the partial pattern which begins at i_head with the pattern itself.
    while(i_head < pattern.size() - 1)
    {
        // i_pattern -1 means comparison of the first character was failed.
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