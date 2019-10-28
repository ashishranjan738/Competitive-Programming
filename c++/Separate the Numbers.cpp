#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
long long conv_number(const string &s){
    return atoll(s.c_str());
}
string conv_string(long long int number){
    return to_string(number);
}
bool isPresent(const string &temp,const string & s,int index){
    if((index+temp.length()-1)>=s.length()){
        //cout<<index<<" "<<temp.length()<<" "<<s.length();
        //cout<<"return false\n";
        return false;
    }
    for(int i=0;i<temp.length();i++){
        //cout<<"test123 "<<temp[i]<<" "<<s[index]<<endl;
        if(temp[i]==s[index]){
            index++;
        }
        else{
            //cout<<"Hello";
            return false;
        }
    }
    return true;
}
bool isBeautiful(const string &s , const string & temp,int index){
    long long int temp1=conv_number(temp);
    temp1++;
    string temp2=conv_string(temp1);
    //cout<<temp2<<endl;
    while(index<s.length()){
        if(isPresent(temp2,s,index)){
            index+=temp2.length();
            temp1=conv_number(temp2);
            temp1++;
            temp2=conv_string(temp1);
        }
        else return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string first;
        bool flag = false;
        string temp;
        for(int i=0;i<s.length()/2;i++){
            temp+=s[i];
            if(isBeautiful(s,temp,i+1)){
                first=temp;
                flag=1;
                break;
            }
        }
        flag?cout<<"YES "<<first<<endl:cout<<"NO \n";
    }
return 0;}
