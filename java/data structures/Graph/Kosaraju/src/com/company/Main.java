package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.addEdge(1, 0);
        g.addEdge(0, 2);
        g.addEdge(2, 1);
        g.addEdge(0, 3);
        g.addEdge(3, 4);

        for(ArrayList<Integer> s:g.getStronglyConnectedGraph()){
           for(int i:s){
               System.out.print(i + " ");

           }
            System.out.println();
        }
    }
}
