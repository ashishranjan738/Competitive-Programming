#include<bits/stdc++.h>
using namespace std;
struct job{
    int id;
    int bt;
    int art;
    bool finished;
};
int main(){
int n;
cout<<"Enter the number of process with arrival time and brust time \n"'
cin>>n;
job arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i].art>>arr[i].bt;
    arr[i].id=i+1;
    arr[i].finished=false;
}
cout<<"Enter the quantum value \n";
int q;
cin>>q;

return 0;}
