package com.company;

import java.util.ArrayList;

public class StepByKNight {
    static int calculateSteps(int arr[][], int i,int j, int x, int y,int n) {
        if(i>=n || i<0 || j>=n || j<0 || arr[i][j]!=0) {
            return 100;
        }
        if(i==x && j==y){
            return 1;
        }
        arr[i][j]=1;
        int ans1,ans2,ans3,ans4;
        ans1=Math.min(calculateSteps(arr,i+2,j+1,x,y,n),calculateSteps(arr,i+2,j-1,x,y,n));
        ans2=Math.min(calculateSteps(arr,i-2,j+1,x,y,n),calculateSteps(arr,i-2,j-1,x,y,n));
        ans3=Math.min(calculateSteps(arr,i+1,j+2,x,y,n),calculateSteps(arr,i+1,j-2,x,y,n));
        ans4=Math.min(calculateSteps(arr,i-1,j+2,x,y,n),calculateSteps(arr,i-1,j-2,x,y,n));

        return Math.min(Math.min(ans1,ans2),Math.min(ans3,ans4))+1;
    }
    public static void main(String[] args) {
        int arr[][]=new int[6][6];
        System.out.println(calculateSteps(arr,3,4,0,0,6));

    }
}
