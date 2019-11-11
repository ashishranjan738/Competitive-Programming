package com.company;

import com.sun.org.apache.xpath.internal.operations.Bool;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class WordLadder {
    class test{
        int cal;
    }

    private Boolean isAdjacent(String a,String b){
        int count=0;
        for(int i=0;i<a.length();i++){
            if(a.charAt(i)==b.charAt(i)){
                count++;
                if(count>1){
                    return false;
                }
            }
        }
        return count==1?true:false;
    }

//    private int calculate(String start, String target, LinkedList<String> dict){
//        Queue<String> q=new LinkedList<>();
//        int ans=0;
//        while(!q.isEmpty()){
//            dict.
//        }
//    }
}
