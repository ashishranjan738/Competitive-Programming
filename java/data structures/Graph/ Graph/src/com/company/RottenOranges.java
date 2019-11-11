package com.company;
//URL: https://practice.geeksforgeeks.org/problems/rotten-oranges/0/?track=SPC-Graph&batchId=135

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class RottenOranges {
    class loc {
        int x,y;
        public int getX() {
            return x;
        }
        public int getY() {
            return y;
        }
        loc(int x, int y){
            this.x=x;
            this.y=y;
        }
    }

    private Boolean isValid(loc t,int x,int y){
        return t.getY()<y && t.getY()>=0 &&t.getX()<x && t.getX()>=0;
    }

    private int ans(int arr[][]){
        int n=arr.length;
        int m=arr.length>0?arr[0].length:0;

        Queue<loc> q=new LinkedList<>();
        ArrayList<loc> ones=new ArrayList<>();
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(arr[i][j]==1){
                    ones.add(new loc(i,j));
                }else if (arr[i][j]==2){
                    q.offer(new loc(i,j));
                }
            }
        }

        int ans=0;
        q.offer(new loc(-1,-1));
        while(!q.isEmpty()){
            loc f=q.poll();
            if(f.getX()==-1 && f.getY()==-1){
                if(q.isEmpty()){
                    break;
                } else {
                    q.offer(new loc(-1,-1));
                    ans++;
                    continue;
                }
            }
            loc up=new loc(f.getX(),f.getY()-1);
            if(isValid(up,n,m)&& arr[up.getX()][up.getY()]==1){arr[up.getX()][up.getY()]=2;q.offer(up);}
            loc down =new loc(f.getX(),f.getY()+1);
            if(isValid(down,n,m)&& arr[down.getX()][down.getY()]==1){arr[down.getX()][down.getY()]=2;q.offer(down);}
            loc right =new loc(f.getX()+1,f.getY());
            if(isValid(right,n,m)&& arr[right.getX()][right.getY()]==1){arr[right.getX()][right.getY()]=2;q.offer(right);}
            loc left =new loc(f.getX()-1,f.getY());
            if(isValid(left,n,m)&& arr[left.getX()][left.getY()]==1){arr[left.getX()][left.getY()]=2;q.offer(left);}
        }

        for(loc v:ones){
            if(arr[v.getX()][v.getY()]==1){
                return -1;
            }
        }
        return ans;
    }


    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        RottenOranges a=new RottenOranges();
        while(t-->0){
            int x,y;
            x=sc.nextInt();y=sc.nextInt();
            int arr[][]=new int[x][y];
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    arr[i][j]=sc.nextInt();
                }
            }
            System.out.println(a.ans(arr));
        }
    }
}
