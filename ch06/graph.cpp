#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

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

    void bfs(int v0)
    {
        int count = 0;
        for (int i = 0; i < data.size(); i++)
        {
            data[i] = 0;
        }
        queue<int> q;
        q.push(v0);
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

    void dfs(int v0)
    {
        int count = 0;
        for (int i = 0; i < data.size(); i++)
        {
            data[i] = 0;
        }
        stack<int> s;
        s.push(v0);
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

    void dfs_recursive(int v0)
    {
        int count = 0;
        for (int i = 0; i < data.size(); i++)
        {
            data[i] = 0;
        }
        if (data[v0] == 0)
        {
            data[v0] = ++count;
            for (int u : neighbor_list[v0])
            {
                if (data[u] == 0) dfs_recursive(u);
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

const int INF = 100000001;
const int d[9][9] =
{ 
    {  0,  70, INF, 170, 230, INF, INF, INF, INF},
    { 70,   0,  80, INF, INF, INF, INF, INF, INF},
    {INF,  80,   0, INF, 140, INF, INF, INF, INF},
    {170, INF, INF,   0, INF,  90, INF, INF, 230},
    {230, INF, 140, INF,   0, INF,  40, INF, INF},
    {INF, INF, INF,  90, INF,   0, 210, INF, 200},
    {INF, INF, INF, INF,  40, 210,   0, 180, INF},
    {INF, INF, INF, INF, INF, INF, 180,   0, INF},
    {INF, INF, INF, 230, INF, 200, INF, 180,   0}
};

class Network : public Graph
{
public:
    vector<int> dist;
    vector<bool> visit;

    Network(int n) : Graph(n)
    {
        dist.resize(n);
        visit.resize(n, false);
    }

    void dijkstra(int v0)
    {
        set<int> N;
        for (int i = 0; i < data.size(); i++)
        {
            visit[i] = false;
        }
        N.insert(v0);
        dist[v0] = 0;
        while(!N.empty())
        {
            int v;
            int m = INF;
            for (int w : N)
            {
                if (m > dist[w])
                {
                    m = dist[w];
                    v = w;
                }
            }
            visit[v] = true;
            N.erase(v);
            for (int u : neighbor_list[v])
            {
                if (visit[u] == false)
                {
                    // if (N.contains(u)) (from C++20)
                    if (N.find(u) != N.end())
                    {
                        dist[u] = min(dist[u], dist[v] + d[v][u]);
                    }
                    else
                    {
                        N.insert(u);
                        dist[u] = dist[v] + d[v][u];
                    }
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
            cout << "dist : " << dist[i] << endl;
            cout << "---" << endl;
        }
    }
};

int N = 9;

int main()
{
    Network net(N);
    net.neighbor_list[0] = {1, 3, 4};
    net.neighbor_list[1] = {0, 2};
    net.neighbor_list[2] = {1, 4};
    net.neighbor_list[3] = {0, 5, 8};
    net.neighbor_list[4] = {0, 2, 6};
    net.neighbor_list[5] = {3, 6, 8};
    net.neighbor_list[6] = {4, 5, 7};
    net.neighbor_list[7] = {6, 8};
    net.neighbor_list[8] = {3, 5, 7};
    net.dijkstra(0); net.print_graph();
}