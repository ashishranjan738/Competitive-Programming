#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, vector<bool> &visited);

  public:
    Graph(int v);
    void addEdge(int v, int w);
    int findMother();
    void printAdj();
};

Graph::Graph(int v)
{
    this->V = v;
    adj = new list<int>[v];
}

void Graph::printAdj()
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " : ";
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}

void Graph::DFSUtil(int v, vector<bool> &visited)
{
    visited[v] = true;
    for (auto it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if (!visited[*it])
        {
            DFSUtil(*it, visited);
        }
    }
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

int Graph::findMother()
{
    vector<bool> visited(V, false);

    int lastVisisted = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFSUtil(i, visited);
            lastVisisted = i;
        }
    }

    fill(visited.begin(), visited.end(), false);
    DFSUtil(lastVisisted, visited);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            return -1;
    }
    return lastVisisted;
}

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);

    g.printAdj();

    cout << "A mother vertex is " << g.findMother();

    return 0;
}