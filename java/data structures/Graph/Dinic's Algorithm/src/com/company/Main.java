package com.company;

public class Main {

    public static void main(String[] args) {
//		Graph g=new Graph(6);
//		g.addEdge(0, 1, 16 );
//		g.addEdge(0, 2, 13 );
//		g.addEdge(1, 2, 10 );
//		g.addEdge(1, 3, 12 );
//		g.addEdge(2, 1, 4 );
//		g.addEdge(2, 4, 14);
//		g.addEdge(3, 2, 9 );
//		g.addEdge(3, 5, 20 );
//		g.addEdge(4, 3, 7 );
//		g.addEdge(4, 5, 4);
		Graph g2= new Graph(6);
		g2.addEdge(0,1,10);
		g2.addEdge(0,2,10);
		g2.addEdge(1,3,4);
		g2.addEdge(1,2,2);
		g2.addEdge(1,4,8);
		g2.addEdge(2,4,9);
		g2.addEdge(4,3,6);
		g2.addEdge(3,5,10);
		g2.addEdge(4,5,10);
		System.out.println(g2.getMaximumFlow(0,5));
    }
}
