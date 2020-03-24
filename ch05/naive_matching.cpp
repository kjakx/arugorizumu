#include <iostream>
#include <string>

using namespace std;

int naive_matching(string text, string pattern);

int main()
{
    string text = "string pattern matching";
    string pattern = "ing";
    int pos;
    pos = naive_matching(text, pattern);
    if (pos < 0) cout << "not found" << endl;
    else cout << "pattern found at " << pos << endl;
}

int naive_matching(string text, string pattern)
{
    int i_text = 0;
    int i_pattern = 0;
    int i_head = 0;
    int pos = -1;
    while (i_head < text.size() - pattern.size() + 1 && i_pattern < pattern.size())
    {
        if (text[i_text] == pattern[i_pattern])
        {
            i_text++;
            i_pattern++;
        }
        else
        {
            i_head++;
            i_text = i_head;
            i_pattern = 0;
        }
    }
    if (i_pattern == pattern.size())
    {
        pos = i_head;
    }
    return pos;
}