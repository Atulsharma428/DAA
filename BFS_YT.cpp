#include <bits/stdc++.h>
#include <map>
using namespace std;

template <typename T>

class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void BFS(T src)
    {
        map<T, int> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (int nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 5);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 6);
    g.addEdge(3, 7);
    g.addEdge(5, 6);
    g.addEdge(6, 5);
    g.addEdge(6, 7);

    g.BFS(0);
    return 0;
}