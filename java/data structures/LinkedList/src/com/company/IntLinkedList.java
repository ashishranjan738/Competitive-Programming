package com.company;

public class IntLinkedList {
    public Node head;

    class Node {
        private int val;
        private Node link;
        public Node(int val,Node link) {
            this.val=val;
            this.link=link;
        }
    }

    public void insertInTheBegining(int val) {
        Node n=new Node(val,this.head);
        this.head=n;
    }

    public void deleteNode(int val) {
        Node ptr=head,prv=head;
        while(ptr!=null) {
            if (ptr.val == val) {
                if(prv==head)
                    head=ptr.link;
                else
                    prv.link = ptr.link;
                return;
            }
            prv=ptr;
            ptr=ptr.link;
        }
    }

    public void printAllNodes() {
        Node ptr=head;
        while (ptr!=null){
            System.out.println(ptr.val);
            ptr=ptr.link;
        }
    }

}
