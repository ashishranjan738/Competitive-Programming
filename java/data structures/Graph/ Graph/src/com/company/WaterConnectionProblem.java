package com.company;
//
//import java.util.*;
//
//public class WaterConnectionProblem {
//    class node {
//        int dest;
//        int weight;
//        node(int dest,int weight){
//            this.dest=dest;
//            this.weight=weight;
//        }
//    }
//    private  void topologicalSortUtil(Integer min ,int v, boolean visited[], Stack stack,HashMap<Integer,ArrayList<node>> m)
//    {
//        visited[v] = true;
//        node i;
//
//        Iterator<node> it = m.get(v).iterator();
//        while (it.hasNext())
//        {
//            i = it.next();
//            if (!visited[i.dest])
//                topologicalSortUtil(min,i.dest, visited, stack,m);
//        }
//        min=Math.min(min,)
//        stack.push(new Integer(v));
//    }
//
//
//    public  void topologicalSort(HashMap<Integer,ArrayList<node>> m)
//    {
//        Stack stack = new Stack();
//
//        boolean visited[] = new boolean[m.size()+1];
//        for (int i = 0; i < m.size()+1; i++)
//            visited[i] = false;
//
//        for (int i = 0; i <= m.size(); i++)
//            if (visited[i] == false){
//                Integer min=new Integer(Integer.MAX_VALUE);
//                Integer lastValue=new Integer(i);
//
//                topologicalSortUtil(i, visited, stack,m);
//            }
//
//
//        while (stack.empty()==false)
//            System.out.print(stack.pop() + " ");
//    }
//
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        int t=sc.nextInt();
//        while(t-->0){
//            int n=sc.nextInt();
//            int e=sc.nextInt();
//
//            HashMap<Integer, ArrayList<Integer>> m=new HashMap<>();
//            for(int i=1;i<=n;i++){
//                m.put(i,new ArrayList<>());
//            }
//            for(int i=0;i<e;i++){
//                int src=sc.nextInt();int dest=sc.nextInt();int weight=sc.nextInt();
//                node n=new node(dest,weight);
//                m.get(src).add(n);
//            }
//            topologicalSort(m);
//        }
//    }
//}
