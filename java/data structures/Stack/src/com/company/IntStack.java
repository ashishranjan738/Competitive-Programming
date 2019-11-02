package com.company;

public class IntStack {
    private int []stack;
    private  int top,size;
    public IntStack(){
        this.top=-1;
        this.size=50;
        stack=new int[this.size];
    }
    public IntStack(int size){
        this.top=-1;
        this.size=size;
        stack=new int[this.size];
    }
    public boolean push(int val) {
        if (!isFull()){
            top++;
            stack[top]=val;
            return true;
        }
        return false;
    }

    public int pop() {
        return !isEmpty()? stack[top--]:-1;

    }

    public boolean isFull() {
        return top==stack.length-1? true:false;
    }

    public boolean isEmpty() {
        return top<0? true:false;
    }

    public static void main(String args[]) {
        System.out.println("Hello");
    }

}
