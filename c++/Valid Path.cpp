#include<bits/stdc++.h>
using namespace std;

int deltax[]={1,-1,0,0,1,-1,-1,1};
int deltay[]={0,0,-1,1,-1,-1,1,1};

void mark_circles(int cx,int cy,int x,int y,int r,vector<vector<bool>> &v){ // Marking the points which are inside any circle
    v[cx][cy]=1;
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(sqrt(pow(cx-i,2)+pow(cy-j,2))<=r)
                v[i][j]=true;
        }
    }
}

bool can_we_reach(vector<vector<bool>> &grid,int x,int y,int cx,int cy) {
    if(cx<0 || cx>x || cy<0 || cy>y || grid[cx][cy])
        return 0;
    if(cx==x && cy==y)
        return 1;
    grid[cx][cy]=1;
    for(int di=0;di<8;di++){
        if(can_we_reach(grid,x,y,cx+deltax[di],cy+deltay[di]))
            return 1;
    }
    return 0;
}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<bool>> grid(A+1,vector<bool>(B+1,0));
    for(int i=0;i<C;i++)
        mark_circles(E[i],F[i],A,B,D,grid);
    if(can_we_reach(grid,A,B,0,0))
        return "YES";
    return "NO";
}


int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int s;
    cin>>s;
    vector<int> v1(s);
    for(int &t:v1)
        cin>>t;
    cin>>s;
    vector<int> v2(s);
    for(int &t:v2)
        cin>>t;
    cout<<solve(a,b,c,d,v1,v2);
    return 0;
}
