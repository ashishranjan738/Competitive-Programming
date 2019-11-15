package com.company;

import java.util.ArrayList;

// Bellman Ford algorithm doesn't work for negative weighted cycle

public class Graph {
    class Edge{
        int src,dest,weight;
        Edge(int src,int dest,int weight){
            this.src=src;
            this.dest=dest;
            this.weight=weight;
        }
    }

    int vertices;
    ArrayList<Edge> edges;
    Graph(int vertices){
        this.vertices=vertices;
        edges=new ArrayList<>();
    }

    public void addEdge(int src,int dest,int weight){
        edges.add(new Edge(src,dest,weight));
    }

    public ArrayList<Integer> getSingeShortestPath(int src){
        int dist[]=new int[vertices];
        for(int i=0;i<vertices;i++){
            dist[i]=Integer.MAX_VALUE;
        }
        dist[src]=0;
        for(int i=0;i<vertices-1;i++){
            for(Edge edge:edges){
                if(dist[edge.src]!=Integer.MAX_VALUE && dist[edge.dest]>edge.weight+dist[edge.src]){
                    dist[edge.dest]=edge.weight+ dist[edge.src];
                }
            }
        }

        for(Edge edge:edges){
            if(dist[edge.src]!=Integer.MAX_VALUE && dist[edge.dest]>edge.weight+dist[edge.src]){
                System.out.println("Negative sum cycle exists in the graph");
                return new ArrayList<>();
            }
        }
        ArrayList<Integer> ans=new ArrayList<>();
        for(int i=0;i<vertices;i++){
            ans.add(dist[i]);
        }
        return ans;
    }

    public void printSingleSourceShortestPath(int src){
        for(int ans: getSingeShortestPath(src)){
            System.out.print(ans+" ");
        }
        System.out.println();
    }
}
