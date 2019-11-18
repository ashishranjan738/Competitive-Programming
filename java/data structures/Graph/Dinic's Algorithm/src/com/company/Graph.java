package com.company;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Graph {
    private int vertices;
    private ArrayList<Edge> edges[];

    class Edge{
        int dest,capacity;
        Edge(int dest,int capacity){
            this.dest=dest;
            this.capacity=capacity;
        }
    }

    Graph(int vertices){
        this.vertices=vertices;
        edges=new ArrayList[vertices];
        for(int i=0;i<vertices;i++)
            edges[i]=new ArrayList<>();
    }

    public void addEdge(int src,int dest,int capacity){
        edges[src].add(new Edge(dest,capacity));
        edges[dest].add(new Edge(src,0));
    }

    // Marking the levels
    private void BFSUtil(int src,int levels[]){
        boolean visited[]=new boolean[vertices];
        Queue<Integer> q=new LinkedList<>();
        q.add(src);
        int currLevel=0;
        levels[src]=currLevel;
        while(!q.isEmpty()){
            int p=q.poll();
            visited[p]=true;
            currLevel++;
            for(Edge child:edges[p]){
                if(!visited[child.dest] && child.capacity>0){
                    q.add(child.dest);
                    visited[child.dest]=true;
                    levels[child.dest]=currLevel;
                }
            }
        }
    }


    private int DFSUtil(int src,int sink,int levels[],int bottleNeck,boolean visited[]){
        if(sink==src){
            System.out.print(src);
            return bottleNeck;
        }
        visited[src]=true;
        for(Edge child:edges[src]){
            if(!visited[child.dest] && child.capacity>0 && levels[child.dest]>levels[src]){
                int finalBottleNeck=DFSUtil(child.dest,sink,levels,Math.min(child.capacity,bottleNeck),visited);
                if(finalBottleNeck!=Integer.MAX_VALUE){// update edges
                    child.capacity-=finalBottleNeck;
                    for(Edge t:edges[child.dest]){
                        if(t.dest==src){
                            t.capacity+=finalBottleNeck;
                        }
                    }
                    System.out.print("->"+ src);
                    return finalBottleNeck;
                }
            }
        }
        return Integer.MAX_VALUE;
    }

    public int getMaximumFlow(int src,int sink){
        int levels[]=new int[vertices];
        BFSUtil(src,levels);
        int maxFlow=0;
        for(int t=0;t!=Integer.MAX_VALUE;){
            BFSUtil(src,levels);
            t=DFSUtil(src,sink,levels,Integer.MAX_VALUE,new boolean[vertices]);
            if(t!=Integer.MAX_VALUE)
                maxFlow+=t;
            System.out.println();
        }
        return maxFlow;
        //        int b=;
//        System.out.println("\nBottle Neck: "+b);

//        for(int i=0;i<vertices;i++){
//            System.out.print(i+" : ");
//            for(Edge e: edges[i]){
//                System.out.print("{"+ e.dest +" | "+e.capacity+" }  ");
//            }
//            System.out.println();
    }

}
