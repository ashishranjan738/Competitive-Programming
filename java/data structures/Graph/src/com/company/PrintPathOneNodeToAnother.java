package com.company;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Stack;

public class PrintPathOneNodeToAnother {
        static ArrayList<Integer> getPath(ArrayList<ArrayList<Integer>> list, int s, int d)
        {
            Stack<Integer> st=new Stack<>();
            HashMap<Integer, Boolean> m=new HashMap<>();
            st.push(s);
            ArrayList<Integer> ans=new ArrayList<>();
            while(!st.empty()){
                Integer p=st.peek();
                m.put(p,true);
                ArrayList<Integer> children=list.get(p);
                if(p==d){

                    while (!st.empty()){
                        ans.add(st.pop());
                    }
                    return ans;
                }

                for(Integer c:children){
                    if(!m.get(c)){
                        st.push(c);
                    }
                }
            }
            st.pop();
            return ans;
        }

}
