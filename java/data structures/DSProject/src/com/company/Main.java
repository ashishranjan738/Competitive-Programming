package com.company;

public class Main {

    public static void main(String[] args) {
	HashTable hashTable=new HashTable();
	Student s1=new Student("Ashish1","123",7.0);
        Student s2=new Student("Ashish2","124",7.0);
        Student s3=new Student("Ashish3","125",7.0);
        Student s4=new Student("Ashish4","132",7.0);

        int s1key=hashTable.toHashCode(s1.getRollNo());
        int s2key=hashTable.toHashCode(s2.getRollNo());
        int s3key=hashTable.toHashCode(s3.getRollNo());
        int s4key=hashTable.toHashCode(s4.getRollNo());

        hashTable.insert(s1key,s1);
        hashTable.insert(s2key,s2);
        hashTable.insert(s3key,s3);
        hashTable.insert(s4key,s4);

        hashTable.printAllStudents();

        hashTable.deleteStudent("124");
        hashTable.printAllStudents();
    }
}
