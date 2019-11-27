#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int e;
    vector<vector<int>> adjList;
    bool detectCycleUtil(bool visited[],int src, bool inStack[]){
        if(!visited[src]){
            visited[src]=true;
            inStack[src]=true;
            for(int child:adjList[src]){
                if(!visited[child] && detectCycleUtil(visited,child,inStack))
                    return true;
                else if(inStack[child])
                    return true;
            }
            inStack[src]=false;
        }
        return false;
    }
public:
    Graph(int e)
    {
        this->e = e;
        this->adjList = vector<vector<int>>(e);
    }
    void addEdge(int src, int dest)
    {
        this->adjList[src].push_back(dest);
    }

    bool detectCycle()
    {
        bool visited[e],inStack[e];
        fill_n(visited,e,false);
        fill_n(visited,e,false);
        for(int i=0;i<e;i++){
            if(detectCycleUtil(visited,i,inStack))
                return true;
        }
        return false;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    cout<<g.detectCycle();
    return 0;
}