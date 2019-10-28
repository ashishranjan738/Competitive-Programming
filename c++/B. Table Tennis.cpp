#include<bits/stdc++.h>
using namespace std;
struct p{
    int power;
    int score;
};
int main(){
    queue<p> q;
    int n;
    long long int k;
    cin>>n>>k;
    int tmin=INT_MIN;
    //cout<<n<<k;
    for(int i=0;i<n;i++){
        p t;
        cin>>t.power;
        //cout<<t.power;
        t.score=0;
        q.push(t);
        //cout<<"Hello \n";
        if(t.power>tmin)
            tmin=t.power;
    }
    if(k>n){
        cout<<tmin<<endl;
        //return 0;
    }
    else{
        p t1,t2;
        t1=q.front();
        q.pop();
        t2=q.front();
        q.pop();
        while(t1.score!=k && t2.score!=k){
            //cout<<t1.score<<" "<<t1.power<<" "<<t2.score<<" "<<t2.power<<endl;
            if(t1.power>t2.power){
                t1.score++;
                t2.score=0;
                q.push(t2);
                t2=q.front();
                q.pop();
            }
            else{
                t2.score++;
                t1.score=0;
                q.push(t1);
                t1=q.front();
                q.pop();
            }
        }
        (t1.score==k)?cout<<t1.power:cout<<t2.power ;
    }
    return 0;
}
