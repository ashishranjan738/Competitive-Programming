#include <bits/stdc++.h>
using namespace std;
struct Node
{
string data;
Node* next;
};
Node *newNode(string str)
{
    Node *new_node = new Node;
    new_node->data = str;
    new_node->next = NULL;
    return new_node;
}
bool Compute(Node* root)
{
   Node* temp=root;
   string s;
   while(temp){
       s.append(temp->data);
       temp=temp->next;
   }
   string temps=s;
   reverse(temps.begin(),temps.end());
   cout<<endl<<s<<endl<<temps<<endl;
   for(int i=0;i<s.length();i++){
       if(s[i]!=temps[i])
            return false;
   }
   return true;
}
void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<endl;
temp=temp->next;
}
}

int main() {
	int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
                struct Node *temp = head;
		for(int i=0;i<K;i++){
		string str="";
		cin>>str;
			if(head==NULL)
			head=temp=newNode(str);
			else
			{
				temp->next = newNode(str);
				temp=temp->next;
			}
		}
		if(Compute(head))
			cout<<"True"<<endl;
		else
			cout<<"False"<<endl;
	}
	return 0;
}
