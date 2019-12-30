#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::maxPoints(vector<int> &A, vector<int> &B);
};

// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

// Sample Input :

// (1, 1)
// (2, 2)
// Sample Output :

// 2
// You will be given 2 arrays X and Y. Each point is represented by (X[i], Y[i])

int gcd(int a, int b) {
    if(!b)
        return a;
    return gcd(b,a%b);
}
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int ans=0;
    int n=A.size();
    if(A.size()<2)
        return A.size();
    
    // we need to calculate the slope {slope=(x2-x1)/(y2-y1)}
    // between each point and find the maximum occuring slope
    // and along with this we need to handle some special 
    // cases like:
    // -> if the points are same (or overlapping) we don't 
    //    need to find the slope for that, instead we can 
    //    directly count them.
    // -> if the slope is infinite (or x1==x2), then also 
    //    we can directly count it.
    // Instead of storing the slope in decimal format (which 
    // can cause precision error) we can divide delta x and 
    // delta y by their GCD and map them as a string.
        for(int i=0;i<n;i++){
        int samePoint=1,localMax=0,vertical=0;
        unordered_map<string,int> m;
        for(int j=i+1;j<n;j++){
            int x1=A[i],y1=B[i],x2=A[j],y2=B[j];
            if(x1==x2 && y1==y2) // case 1
                samePoint++;
            else if(x1==x2) // case 2
                vertical++;
            else {
                int dx=x2-x1,dy=y2-y1,gcdVal=gcd(dx,dy);
                // storing slope as string instead of decimal
                string slope=to_string(dx/gcdVal)+"_"+to_string(dy/gcdVal);
                localMax=max(localMax,++m[slope]);
            }
            localMax=max(localMax,vertical);
        }
        ans=max(ans,localMax+samePoint);
    }
    return ans;
}