#include<bits/stdc++.h>
using namespace std;
map<int,bool> m1;
map<int,bool> m2;
map<int,bool> m3;
bool check(vector<int> &v){
    if(m1[v[0]])
        return 0;
    if(m2[v[1]])
        return 0;
    if(m3[v[2]])
        return 0;
    return 1;
}
int main(){
    int n,m;
    cin>>n>>m;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int sum=0;
    int l,r;
    sort(A,A+n);
    for (int i=0; i<n-2; i++)
    {
        l = i + 1;
        r = n-1;
        while (l < r)
        {
            //cout<<(A[i] + A[l] + A[r])<<endl;
            if( (A[i] + A[l] + A[r]) % m==0)
            {
                //printf("Triplet is %d, %d, %d", A[i],
                                         //A[l], A[r]);
                //return true;
                vector<int> v;
                v.push_back(A[i]);
                v.push_back(A[l]);
                v.push_back(A[r]);
                sort(v.begin(),v.end());
                if(check(v)){
                    m1[v[0]]=true;
                    m2[v[1]]=true;
                    m3[v[2]]=true;
                    sum++;
                }
                r--;
                l++;

            }
            else if (A[i] + A[l] + A[r] < (A[i] + A[l] + A[r]) % m+(A[i] + A[l] + A[r]))
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
    cout<<sum;
    return 0;
}
