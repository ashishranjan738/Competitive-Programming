package com.company;

import java.util.ArrayList;

public class Graph {
    int vertex;
    int adjMatrix[][];
    Graph(int vertex){
        this.vertex=vertex;
        for(int i=0;i<vertex;i++)
            for(int j=0;j<vertex;j++)
                adjMatrix[i][j]=Integer.MAX_VALUE;
    }
    public void addEdge(int src,int dest,int weight){
        adjMatrix[src][dest]=weight;
        adjMatrix[dest][src]=weight;
    }

    public static int minDistanceindex(boolean visited[],int distance[],int v){
        int min=Integer.MAX_VALUE;
        int minIndex=-1;
        for(int i=0;i<v;i++){
            if(!visited[i] && min>distance[i]){
                min=distance[i];
                minIndex=i;
            }
        }
        return minIndex;
    }
    public void dijkstra(ArrayList<ArrayList<Integer>> list,int src,int v){
        boolean visited[]=new boolean[v];
        int distance[]=new int[v];
        for(int i=0;i<v;i++){
            if(i==src){
                distance[i]=0;
            }else{
                distance[i]=Integer.MAX_VALUE;
            }
        }
        for(int cnt=0;cnt<v;cnt++){
            int minIndex=minDistanceindex(visited,distance,v);
            visited[minIndex]=true;
            for(int adj=0;adj<v;adj++){
                if(!visited[adj] && list.get(minIndex).get(adj)!=0 && distance[minIndex]!=Integer.MAX_VALUE && distance[minIndex]+list.get(minIndex).get(adj)<distance[adj]){
                    distance[v]=distance[minIndex]+list.get(minIndex).get(adj);
                }
            }
        }
        for(int i:distance){
            System.out.print(i+" ");
        }
        System.out.println();
    }


}
