package com.company;

public class HashTable {
    private StdList[] arr;
    private int size,totalStudents;

    public HashTable(){
        this.size=1000;
        this.arr=new StdList[this.size];
    }

    public int toHashCode(String rollNo){
        int asciis=0;
        for(char i:rollNo.toCharArray()){
            asciis+=(int)i;
        }
        return asciis%arr.length;
    }
    public boolean insert(int key, Student data) {
        if (arr[key]==null){
            arr[key]=new StdList();
        }
        arr[key].insertStd(data);
        totalStudents++;
        return true;
    }

    public void printAllStudents(){
        for(StdList a:arr){
            if (a!=null)
                a.showAll();
        }
    }

    public void deleteStudent(String RollNo){
        int hashCode=toHashCode(RollNo);
        if(arr[hashCode]!=null){
             arr[hashCode].deleteStudent(RollNo);
        }
    }
}
