package com.company;

import org.omg.CORBA.INTERNAL;

import java.util.*;

public class TwoWayAttack {
    public static boolean canAssign(int cv,ArrayList<Integer> children,HashMap<Integer,Integer> map){
        for(int i:children){
            if(map.containsKey(i)){
                if(Math.abs(cv-map.get(i))>2){
                    return false;
                }
            }
        }
        return true;
    }

    public static int bfs(HashMap<Integer,ArrayList<Integer>> graph,int n){
        int ans=0;
        HashMap<Integer,Integer> visited=new HashMap<>();
        for(int i=1;i<=n;i++){
            int src=i;
            if(visited.containsKey(src)){
                continue;
            }
            if(graph.containsKey(src)){
                Queue<Integer> q=new LinkedList<>();
                q.offer(src);
                while(!q.isEmpty()){
                    int p=q.poll();

                    ArrayList<Integer> children=graph.get(p);
                    if(!canAssign(ans+1, children,visited)){
                        return -1;
                    }
                    if(!visited.containsKey(p)){
                        ans++;
                        visited.put(p,ans);
                    }
                    for(int c:children){
                        if(!visited.containsKey(c)){
                            q.offer(c);
                        }
                    }
                }
            }
            if(!visited.containsKey(i)){
                ans+=2;
            }

        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            int n,x;
            n=sc.nextInt();
            x=sc.nextInt();
            HashMap<Integer, ArrayList<Integer>> m=new HashMap<>();
            for(int i=0;i<x;i++){
                int src,dest;
                src=sc.nextInt();
                dest=sc.nextInt();
                if(m.containsKey(src)){
                    m.get(src).add(dest);
                }else{
                    m.put(src,new ArrayList<>());
                    m.get(src).add(dest);
                }

                if(m.containsKey(dest)){
                    m.get(dest).add(src);
                }
                else{
                    m.put(dest,new ArrayList<>());
                    m.get(dest).add(src);
                }
            }
//            m.forEach((k,v)->System.out.println(k+" "+v.size()));
            int ans=bfs(m,n);
            if(ans==-1){
                System.out.println("NO");
            } else {
                System.out.println("YES");
                System.out.println(ans);
            }
        }
    }
}


