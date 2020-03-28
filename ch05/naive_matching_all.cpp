#include <iostream>
#include <string>
#include <vector>

using namespace std;

void naive_matching(string text, string pattern, vector<int>& matches);
void print_vector(vector<int>& v);

int main()
{
    string text = "string pattern matching";
    string pattern = "ing";
    vector<int> matches;
    int pos;
    naive_matching(text, pattern, matches);
    print_vector(matches);
}

void naive_matching(string text, string pattern, vector<int>& matches)
{
    int i_text = 0;
    int i_pattern = 0;
    int i_head = 0;
    int pos = -1;
    while (i_head < text.size() - pattern.size() + 1)
    {
        if (text[i_text] == pattern[i_pattern])
        {
            i_text++;
            i_pattern++;
            if (i_pattern == pattern.size())
            {
                matches.push_back(i_head);
                i_text = ++i_head;
                i_pattern = 0;
            }
        }
        else
        {
            i_head++;
            i_text = i_head;
            i_pattern = 0;
        }
    }
}

void print_vector(vector<int>& v)
{
    for (int v_elem : v) cout << v_elem << endl;
}