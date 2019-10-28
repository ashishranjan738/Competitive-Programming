#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
struct fruit{
    int a,b,c,d;
};
bool comp(fruit a1,fruit b1){
    return min(min(a1.a,a1.b),min(a1.c,a1.d))>min(min(b1.a,b1.b),min(b1.c,b1.d));
}
int main()
{
    int q,w,e,r;
    cin>>q>>w>>e>>r;
    int n;
    cin>>n;
    fruit arr[n];
    int sum1=0,sum2=0,sum3=0,sum4=0;
    for(int i=0;i<n;i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].c>>arr[i].d;
        sum1+=arr[i].a;
        sum2+=arr[i].b;
        sum3+=arr[i].c;
        sum4+=arr[i].d;

    }
    if(sum1<q||sum2<w||sum3<e||sum4<r){
        cout<<"NO \n";
        return 0;
    }
    int i;
    sort(arr,arr+n,comp);
    for(i=0;i<n;i++)
        cout<<arr[i].a<<" "<<arr[i].b<<" "<<arr[i].c<<" "<<arr[i].d<<endl;
}

