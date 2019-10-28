#include<bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin>>m;
    int arr[m][m];
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    for(int i=0;i<m;i++){
        for(int j=i;j>=0;j--){
            cout<<arr[j][i-j]<<" ";
        }
        cout<<endl;
    }
    int temp=m-1;
    int j=1;
    while(temp!=j){
        int k=j;
        for(int i=temp;i>=j;i--&&k++){
            cout<<arr[i][k]<<" ";
        }
        j++;
        cout<<endl;
    }
    cout<<arr[m-1][m-1];
return 0;}
