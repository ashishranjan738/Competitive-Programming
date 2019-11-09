package com.company;

import java.util.ArrayList;

// Approach for finding the Articulation points is to use DFS (Depth First Search). In DFS, we follow vertices in tree form called DFS tree.
// In DFS tree, a vertex u is parent of another vertex v, if v is discovered by u (obviously v is an adjacent of u in graph). In DFS tree, a
// vertex u is articulation point if one of the following two conditions is true.
// 1) u is root of DFS tree and it has at least two children.
// 2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors (in
// DFS tree) of u.

// We do DFS traversal of given graph with additional code to find out Articulation Points (APs).In DFS traversal, we maintain a parent[] array
// where parent[u] stores parent of vertex u. Among the above mentioned two cases, the first case is simple to detect. For every vertex, count
// children. If currently visited vertex u is root (parent[u] is NIL) and has more than two children, print it.

// How to handle second case? The second case is trickier. We maintain an array disc[] to store discovery time of vertices. For every node u, we
// need to find out the earliest visited vertex (the vertex with minimum discovery time) that can be reached from subtree rooted with u. So we
// maintain an additional array low[] which is defined as follows.
// low[u] = min(disc[u], disc[w])
// where w is an ancestor of u and there is a back edge from
// some descendant of u to w.

// Broadly speaking theoretically the formula to calculate the value of low for any vertices is
// low[current]=min(
//              the current discovery time,
//              the low of all its children,
//              the discovery time of its back edge (or the edge other than parent which connects the current vertex to one of it ancestors)
//           )


public class Graph {
    private static final int NIL=-1;
    int V; // Number of vertices
    private ArrayList<Integer> adjList[];

    private int time=0;

    Graph(int v){
        this.V=v;
        adjList=new ArrayList[v];
        for(int i=0;i<v;i++)
            adjList[i]=new ArrayList<>();
    }

    public void addEdge(int src,int dest){
        adjList[src].add(dest);
        adjList[dest].add(src);
    }


    private void articulationPointHelper(int src,int disc[], Boolean visited[],int low[],int parent[],Boolean ap[]){
        visited[src]=true;
        disc[src]=low[src]=time++;
        int children=0;
        for(int child:adjList[src]){
            if(!visited[child]){
                children++;
                parent[child]=src;
                articulationPointHelper(child,disc,visited,low,parent,ap); // doing the simple DFS call
                low[src]=Math.min(disc[src],low[child]); // calculating the low with the low of its children
                if(parent[src]==NIL && children>1) // checking if it is a root
                    ap[src]=true;
                if(parent[src]!=NIL && low[child]>=disc[src]) // checking if its not a root but a articulation point
                    ap[src]=true;
            } else if(parent[child]!=src){ // calculating the low with back edges (or an vertex which is visited but is not the parent of the current node)
                low[src]=Math.min(low[src],disc[child]);
            }
        }
    }
    public ArrayList<Integer> getArticulationPoints(){
        int discoverNumber[]=new int[V];
        Boolean visited[]=new Boolean[V];
        int lowestReachableVertices[]=new int[V];
        int parent[]=new int[V];
        Boolean ap[]=new Boolean[V];

        for(int i=0;i<V;i++){
            parent[i]=-1;
            visited[i]=false;
            ap[i]=false;
        }


        for(int i=0;i<V;i++){
            if(!visited[i])
                articulationPointHelper(i,discoverNumber,visited,lowestReachableVertices,parent,ap);
        }
//        printing the stack for debugging
//        for(int i =0;i<V;i++){
//            System.out.println(i+" "+discoverNumber[i]+" "+visited[i]+" "+lowestReachableVertices[i]+" "+parent[i]+" "+ap[i]);
//        }

        ArrayList<Integer> ans=new ArrayList<>();
        for(int i=0;i<V;i++){
            if(ap[i]){
                ans.add(i);
            }
        }
        return ans;
    }
}
