package com.company;

import java.util.LinkedList;

public class Graph {
    int vertices;
    LinkedList<Integer>  adjList[];
    Graph(int vertices){
        this.vertices=vertices;
        adjList=new LinkedList[vertices];
        for(int i=0;i<vertices;i++){
            adjList[i]=new LinkedList<>();
        }
    }

    public void addEdge(int src,int dest){
        adjList[src].add(dest);
    }

    private void DFS(int src,boolean isVisited[]){
        isVisited[src]=true;
        for(int child:adjList[src]){
            if(!isVisited[child]){
                DFS(child,isVisited);
            }
        }
    }

    public int getMotherVertex(){
        boolean visisted[]=new boolean[vertices];
        int lastTaken=0;
        for(int i=0;i<vertices;i++){
            if(!visisted[i]){
                DFS(i,visisted);
                lastTaken=i;
            }
        }
        visisted=new boolean[vertices];
        DFS(lastTaken,visisted);
        for(int i=0;i<vertices;i++){
            if(!visisted[i])
                return -1;
        }
        return lastTaken;
    }

    public void printMotherVertex(){
        int motherVertex=getMotherVertex();
        if(motherVertex==-1) System.out.println("No mother vertex present in the graph");
        else System.out.println(motherVertex);
    }
}
