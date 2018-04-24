#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack{
        int top;
public:
    int a[MAX];
    Stack(){top=-1;}
    bool push(int x);
    int pop();
    bool isEmpty();
};
bool Stack::push(int x){
    if(top>=MAX){
        cout<<"Overflow \n";
        return false;
    }
    else{
        a[++top]=x;
        return true;
    }
}
int Stack::pop(){
    if(top<0){
        cout<<"Underflow \n";
        return -1;
    }
    else{
        int x=a[top--];
        return x;
    }
}
bool Stack::isEmpty(){
    return top<0;
}
int main(){
    Stack S;
    S.push(10);
    S.push(11);
    cout<<S.pop();
    cout<<endl;
    cout<<S.pop();
return 0;}
