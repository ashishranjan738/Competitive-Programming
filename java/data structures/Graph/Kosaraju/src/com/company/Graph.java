package com.company;

import java.util.*;

public class Graph {
    private ArrayList<Integer> adjList[];
    private int vertices;
    Graph(int v){
        this.vertices=v;
        adjList=new ArrayList[v];
        for(int i=0;i<v;i++){
            adjList[i]=new ArrayList<>();
        }
    }

    public void addEdge(int src,int dest){
        adjList[src].add(dest);
    }

    public void DFS(int src, Boolean visited[], Stack<Integer> stack,ArrayList<Integer> aList[]){
        visited[src]=true;
        for(int child:aList[src]){
            if(!visited[child]){
                DFS(child,visited,stack,aList);
            }
        }
        stack.push(src);
    }

    public ArrayList<ArrayList<Integer>> getStronglyConnectedGraph(){
        Boolean visited[]=new Boolean[vertices];
        ArrayList<Integer> adjListTransposed[]=new ArrayList[vertices];
        ArrayList<ArrayList<Integer>> ans=new ArrayList<>();

        for(int i=0;i<vertices;i++){
            adjListTransposed[i]=new ArrayList<>();
            visited[i]=false;
        }
        for(int i=0;i<vertices;i++){
            // Taking the transpose of the matrix
            for(int child:adjList[i]){
                adjListTransposed[child].add(i);
            }
        }

//        Printing transpose of the matrix
//        for(int i=0;i<vertices;i++){
//            System.out.print(i+"->");
//            for(int j:adjListTransposed[i]){
//                System.out.print(j+" ");
//            }
//            System.out.println();
//        }
        Stack<Integer> s=new Stack<>();
        for(int i=0;i<vertices;i++){
            if(!visited[i])
                DFS(i,visited,s,adjList);
        }

        // remarking visited as false
        for(int i=0;i<vertices;i++)
            visited[i]=false;
        while(!s.empty()){
            Stack<Integer> st=new Stack<>();
            int p=s.pop();
            if(!visited[p]){
                DFS(p,visited,st,adjListTransposed);
                ans.add(new ArrayList<>(st));
            }
        }

        return ans;
    }
}
