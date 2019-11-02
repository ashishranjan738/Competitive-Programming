package com.company;

public class StdList {
    private Node h;
    public boolean insertStd(Student std) {
        Node n= new Node();
        n.data=std;
        n.next=h;
        h=n;
        return true;
    }

    public boolean  haveRollNo(String rollNo){
        Node a=h;
        while(a!=null) {
            if(rollNo.equals(a.data.getRollNo())) {
                return true;
            }
        }
        return false;
    }

    public Student fetchData(String rollNo) {
        Node ptr=h;
        while(ptr!=null){
            if(rollNo.equals(ptr.data.getRollNo())) {
                return ptr.data;
            }
        }
        return null;
    }

    public void showAll() {
        Node ptr=h;
        while(ptr!=null){
            System.out.println(ptr.data.toString());
            ptr=ptr.next;
        }
    }

    public void deleteStudent(String rollNo) {
        Node ptr=h,prv=h;
        while(ptr!=null){
            if(ptr.data.getRollNo().equals(rollNo)){
                if (prv==h){
                    h=ptr.next;
                } else {
                    prv.next=ptr.next;
                }
            }
            prv=ptr;
            ptr=ptr.next;
        }
    }

    class Node {
        private Student data;
        private Node next;
    }
}
