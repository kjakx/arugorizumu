#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
public:
    vector<vector<int>> neighbor_list;
    vector<int> data;

    Graph(int N)
    {
        neighbor_list.resize(N);
        data.resize(N);
    }

    void bfs()
    {
        int count = 0;
        for (int i = 0; i < data.size(); i++)
        {
            data[i] = 0;
        }
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int w = q.front(); q.pop();
            if (data[w] == 0)
            {
                data[w] = ++count;
                for (int u : neighbor_list[w])
                {
                    if (data[u] == 0) q.push(u);
                }
            }
        }
    }

    void dfs()
    {
        int count = 0;
        for (int i = 0; i < data.size(); i++)
        {
            data[i] = 0;
        }
        stack<int> s;
        s.push(0);
        while (!s.empty())
        {
            int w = s.top(); s.pop();
            if (data[w] == 0)
            {
                data[w] = ++count;
                for (int u : neighbor_list[w])
                {
                    if (data[u] == 0) s.push(u);
                }
            }
        }
    }

    void print_graph()
    {
        for (int i = 0; i < data.size(); i++)
        {
            cout << i;
            for (int u : neighbor_list[i])
            {
                cout << " -> " << u;
            }
            cout << endl;
            cout << "data : " << data[i] << endl;
        }
    }
};

int N = 7;

int main()
{
    Graph G(N);
    G.neighbor_list[0] = {1, 4};
    G.neighbor_list[1] = {2, 4, 5};
    G.neighbor_list[2] = {5};
    G.neighbor_list[3] = {0, 4};
    G.neighbor_list[4] = {3, 5};
    G.neighbor_list[5] = {2, 6};
    G.neighbor_list[6] = {4, 5};
    G.dfs(); G.print_graph();
}