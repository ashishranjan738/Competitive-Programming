package com.company;

public class Main {
    public static void main(String[] args) {
        IntLinkedList n=new IntLinkedList();
        for(int i=0;i<10;i++){
            n.insertInTheBegining(i);
        }
        n.deleteNode(9);
        n.deleteNode(7);
        n.deleteNode(10);
        n.printAllNodes();
    }
}
