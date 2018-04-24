#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> m;
void addVert(int vert,int conn){
    if(find(m[vert].begin(),m[vert].end(),conn)==m[vert].end())m[vert].push_back(conn);
    if(find(m[conn].begin(),m[conn].end(),vert)==m[conn].end())m[conn].push_back(vert);
}
void deleteVert(int vert){
    m.erase(vert);
    for(auto &it:m){
        it.second.erase(find(it.second.begin(),it.second.end(),vert));
    }
}
void print(){
    for(auto &it:m){
        cout<<"Vertex "<<it.first<<":";
        for(int t:it.second)
            cout<<t<<" ";
        cout<<endl;
    }
}
int main(){
    addVert(1,2);
    addVert(1,3);
    addVert(3,4);
    addVert(4,1);
    addVert(4,-1);
    print();
    return 0;
}