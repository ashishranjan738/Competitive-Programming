#include<bits/stdc++.h>
using namespace std;
int main(){
    FILE *fp;
    char ch;
    fp=fopen("xyz.txt","w");
    cout<<"Enter character \n";
    do{
        ch=getchar();
        fputc(ch,fp);
    }while(ch!='\n')
    return 0;
}
