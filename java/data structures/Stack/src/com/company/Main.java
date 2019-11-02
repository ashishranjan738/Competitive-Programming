package com.company;

public class Main {

    public static void main(String[] args) {
	    IntStack s=new IntStack();
	   	s.push(5);
	   	s.push(6);
	    System.out.println(s.pop());
	    System.out.println(s.pop());
	    Person p=new Person("ad");
	    p.toString();
    }
}
