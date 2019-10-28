#include<bits/stdc++.h>
using namespace std;
class Graph {
    int v;
    list<int> *adj;
public:
    Graph(int);
    void addEdge(int,int);
    void BFS(int s);
};
Graph::Graph(int v) {
    this->v=v;
    adj=new list<int>[v];
}
void Graph::addEdge(int v,int w) {
    adj[v].push_back(w);
}
void Graph::BFS(int s){
    queue<int> q;
    bool visited[v];
    q.push(s);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        visited[t]=true;
        for(auto it=adj[t].begin();it!=adj[t].end();it++){
            if (!visited[*it]){
                visited[*it]=true;
                q.push(*it);
            }
        }
        cout<<t<<" ";
    }
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}
