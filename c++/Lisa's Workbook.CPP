#include<bits/stdc++.h>
using namespace std;
struct node{
    int start,finish;
};
node val(int start,int finish){
    node temp;
    temp.start=start;
    temp.finish=finish;
    return temp;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<node> v;
    int sum=0;
    for(int i=0;i<n;i++){
        int j=1;
        while(arr[i]>0){
            if(arr[i]>k-1){
                v.push_back(val(j,j+k-1));
                j+=k;
            }
            else v.push_back(val(j,j+arr[i]-1));
            arr[i]-=k;
        }
    }
    for(int i=0;i<v.size();i++){
        if((i+1)<=v[i].finish&&(i+1)>=v[i].start)
            sum++;
    }
    cout<<sum;
return 0;}
