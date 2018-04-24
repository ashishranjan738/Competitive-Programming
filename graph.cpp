#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
map<int,vector<int>> m;
void addVertexUpdate(int vert,int conn){
     if(find(m[vert].begin(),m[vert].end(),conn)==m[vert].end())m[vert].push_back(conn);
     if(find(m[conn].begin(),m[conn].end(),vert)==m[conn].end())m[conn].push_back(vert);
}
void deleteVertex(int vert){
    m.erase(vert);
    for(auto &it:m){
        cout<<it.second;
    }
}
int main(){


    return 0;
}
