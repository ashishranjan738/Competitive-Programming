#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[18]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
    for(int t=0;t<18;t++){
        for(int i=0;i<64-arr[t];i++)
            cout<<"0";
        for(int i=0;i<arr[t];i++)
            cout<<"1";
        cout<<endl;
    }
    return 0;
}
