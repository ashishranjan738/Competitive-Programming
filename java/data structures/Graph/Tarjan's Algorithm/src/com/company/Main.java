package com.company;

public class Main {
    public static void main(String[] args) {
        System.out.println("SCCs in first graph ");
        Graph g1 = new Graph(5);
        g1.addEdge(1, 0);
        g1.addEdge(0, 2);
        g1.addEdge(2, 1);
        g1.addEdge(0, 3);
        g1.addEdge(3, 4);
        g1.printStronglyConnectedComponents();

        System.out.println("SCCs in second graph");
        Graph g2=new Graph(4);
        g2.addEdge(0, 1);
        g2.addEdge(1, 2);
        g2.addEdge(2, 3);
        g2.printStronglyConnectedComponents();

        System.out.println("SCCs in third graph");
        Graph g3=new Graph(7);
        g3.addEdge(0, 1);
        g3.addEdge(1, 2);
        g3.addEdge(2, 0);
        g3.addEdge(1, 3);
        g3.addEdge(1, 4);
        g3.addEdge(1, 6);
        g3.addEdge(3, 5);
        g3.addEdge(4, 5);
        g3.printStronglyConnectedComponents();

        System.out.println("SCCs in fourth graph");
        Graph g4=new Graph(11);
        g4.addEdge(0,1);g4.addEdge(0,3);
        g4.addEdge(1,2);g4.addEdge(1,4);
        g4.addEdge(2,0);g4.addEdge(2,6);
        g4.addEdge(3,2);
        g4.addEdge(4,5);g4.addEdge(4,6);
        g4.addEdge(5,6);g4.addEdge(5,7);g4.addEdge(5,8);g4.addEdge(5,9);
        g4.addEdge(6,4);
        g4.addEdge(7,9);
        g4.addEdge(8,9);
        g4.addEdge(9,8);
        g4.printStronglyConnectedComponents();

        System.out.println("SCCs in fifth graph");
        Graph g5=new Graph(5);
        g5.addEdge(0,1);
        g5.addEdge(1,2);
        g5.addEdge(2,3);
        g5.addEdge(2,4);
        g5.addEdge(3,0);
        g5.addEdge(4,2);
        g5.printStronglyConnectedComponents();
    }
}
