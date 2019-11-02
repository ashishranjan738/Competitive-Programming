package com.company;

public class PersonStack {
    private Person []stack;
    private  int top,size;
    public PersonStack(){
        this.top=-1;
        this.size=50;
        stack=new Person[this.size];
    }
    public PersonStack(int size){
        this.top=-1;
        this.size=size;
        stack=new Person[this.size];
    }
    public boolean push(Person p) {
        if (!isFull()){
            top++;
            stack[top]=p;
            return true;
        }
        return false;
    }

    public Person pop() {
        return !isEmpty()? stack[top--]:null;
    }

    public boolean isFull() {
        return top==stack.length-1? true:false;
    }

    public boolean isEmpty() {
        return top<0? true:false;
    }
}
