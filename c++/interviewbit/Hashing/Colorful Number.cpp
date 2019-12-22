#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::colorful(int A);
};

// For Given Number N find if its COLORFUL number or not

// Return 0/1

// COLORFUL number:

// A number can be broken into different contiguous sub-subsequence parts. 
// Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
// And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
// Example:

// N = 23
// 2 3 23
// 2 -> 2
// 3 -> 3
// 23 -> 6
// this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

// Output : 1

vector<int> toVector(int a){
    vector<int> ans;
    while(a!=0){
        ans.push_back(a%10);
        a/=10;
    }
    return vector<int> (ans.rbegin(),ans.rend());
}

int toInt(vector<int> a){
    int ans=0;
    for(int i:a){
        ans*=10;
        ans+=i;
    }
    return ans;
}

int product(vector<int> a){
    int ans=1;
    for(int i:a){
        ans*=i;
    }
    return ans;
}

int Solution::colorful(int A) {
    unordered_map<int,bool> m;
    vector<int> v=toVector(A);
    for(int l=1;l<=v.size();l++){
        for(int i=0;i<=v.size()-l;i++){
            vector<int> temp(v.begin()+i,v.begin()+i+l);
            
            int tempInt=toInt(temp);
            int tempProduct=product(temp);
            if(m.find(tempInt)!=m.end() || m.find(tempProduct)!=m.end())
                return 0;
            m[tempProduct]=true;
        }
    }
    return 1;
}
