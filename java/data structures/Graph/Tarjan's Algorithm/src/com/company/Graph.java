package com.company;

import java.util.ArrayList;
import java.util.Stack;

// Explanation and resources:
// https://www.youtube.com/watch?v=TyWtx7q2D7Y
// https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/

public class Graph {
    private int vertex;
    private ArrayList<Integer> adjList[];
    private int time;
    Graph(int vertex){
        this.vertex=vertex;
        this.adjList=new ArrayList[vertex];
        for(int i=0;i<vertex;i++){
            adjList[i]=new ArrayList<>(vertex);
        }
    }

    public void addEdge(int src,int dest){
        adjList[src].add(dest);
    }

    private void DFS(int src, boolean isVisited[],int disc[],int low[], Stack<Integer> s,boolean isOnStack[],ArrayList<ArrayList<Integer>> ans){
        isVisited[src]=true;
        disc[src]=low[src]=time++;
        s.push(src);
        isOnStack[src]=true;
        for(int child:adjList[src]){
            if(!isVisited[child]){
                DFS(child,isVisited,disc,low,s,isOnStack,ans);
                low[src]=Math.min(low[src],low[child]); // We can skip this step now and can do this at the time of popping the scc
            } else if(isOnStack[child]){ // if we have reached to this point that means we have found a cycle and this child has potential for becoming the root of the SCC
                low[src]= Math.min(low[src],low[child]);
            }
        }
        if(low[src]==disc[src]){ // we came back to the root of the SCC after traversing all the child so we can pop out the SCC components now
            ArrayList<Integer> newSCC=new ArrayList<>();
            while(s.peek()!=src){ // popping out the SCC components
                isOnStack[s.peek()]=false;
                low[s.peek()]=low[src];
                newSCC.add(s.pop());

            }
            // popping out the root of the SCC as it got left out by the above while loop
            isOnStack[s.peek()]=false;
            newSCC.add(s.pop());
            ans.add(newSCC);
        }
    }

    public ArrayList<ArrayList<Integer>> getStronglyConnectedComponents(){
        boolean visited[]=new boolean[vertex];
        int disc[]=new int[vertex];
        int low[]=new int[vertex];
        boolean onStack[]=new boolean[vertex];
        Stack<Integer> s=new Stack<>();
        ArrayList<ArrayList<Integer>> ans=new ArrayList<>();
        for(int i=0;i<vertex;i++){
            if(!visited[i])
                DFS(i,visited,disc,low,s,onStack,ans);
        }
        time=0; // Setting this 0 again so that we can recalculate the SCC again if graph changes
        return ans;
    }

    public void printStronglyConnectedComponents(){
        for(ArrayList<Integer> a:getStronglyConnectedComponents()){
            for(int i: a){
                System.out.print(i+" ");
            }
            System.out.println();
        }
    }
}
