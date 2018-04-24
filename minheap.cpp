#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y){
    if(*x!=*y)*x^=*y^=*x^=*y;
}
class MinHeap{
    int* harr;
    int capacity,heap_size;
public:
    MinHeap(int capacity);
    void MinHeapify(int );
    int  parent(int i){return (i-1)/2;}
    int  left(int i){return 2*i+1;}
    int  right(int i){return 2*i+2;}
    int  extractMin();
    void decreaseKey(int i,int new_val);
    int  getMin(){return harr[0];}
    void deleteKey(int i);
    void insertKey(int k);
    void status();
    int hsize(){return heap_size;}
    void changeValue(int pos,int key);
};
void MinHeap::status(){
    cout<<"\nStatus :";
    for(int i=0;i<heap_size;i++)
        cout<<harr[i]<<" ";
    cout<<endl;
}
MinHeap::MinHeap(int cap){
    heap_size=0;
    capacity=cap;
    harr=new int[cap];
    //status();
}
void MinHeap::insertKey(int k){
    if(capacity==heap_size){
        cout<<"Overflow \n";
        return;
    }
    heap_size++;
    int i=heap_size-1;
    harr[i]=k;
    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(&harr[i],&harr[parent(i)]);
        i=parent(i);
    }
    //status();
}
void MinHeap::decreaseKey(int i,int new_val){
    if(i>capacity-1)
        return;
    if(i>heap_size-1){
        cout<<"Element not present \n";
        return;
    }
    harr[i]=new_val;
    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(&harr[i],&harr[parent(i)]);
        i=parent(i);
    }
    //status();
}
void MinHeap::MinHeapify(int i){
    int l=left(i);
    int r=left(i);
    int smallest=i;
    if(l<heap_size && harr[l]<harr[i])
        smallest=l;
    if(l<heap_size && harr[r]<harr[i])
        smallest=r;
    if(smallest!=i){
        swap(&harr[i],&harr[smallest]);
        MinHeapify(smallest);
    }
}
void MinHeap::deleteKey(int i){
    if(i>heap_size-1){
        cout<<"Element not present \n";
        return;
    }
    if(heap_size>1)
        decreaseKey(i,INT_MIN);
    extractMin();
    //status();
}
int MinHeap::extractMin(){
    if(heap_size<=0)
        return INT_MAX;
    if(heap_size==1){
        heap_size--;
        return harr[0];
    }
    int root=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    //status();
    return root;
}
void MinHeap::changeValue(int pos,int val){
    if(pos>heap_size-1){
        cout<<"Element not present \n";
        return;
    }
    else if(val>harr[pos]){
        harr[pos]=val;
        MinHeapify(pos);
    }
    else{
        decreaseKey(pos,val);
    }
}
int main(){
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    int  n;    cin>>n;
    int val;
    cin>>val;
    MinHeap minheap(n);
    for(int i=0;i<val;i++){
        int temp;
        cin>>temp;
        minheap.insertKey(temp);
    }
    minheap.status();
    //cout<<"Hello \n";
    while(1){
        cout<<"\nEnter the value to execute the function:\n1.Extract Min\n2.Change Value\n3.Show Min value\n4.Delete key\n5.Insert key\n";
        int t;
        cin>>t;
        switch(t){
            case 1:cout<<minheap.extractMin();
                    minheap.status();
                    break;
            case 2:int key,pos;
                   cout<<"Enter the position and value :";
                   cin>>pos>>key;
                   minheap.changeValue(pos,key);
                   minheap.status();
                   break;
            case 3:
                   minheap.hsize()?cout<<minheap.getMin()<<endl:cout<<"No Elements present \n";
                   minheap.status();
                   break;
            case 4:cout<<"Enter the position \n";
                   int position;
                   cin>>position;
                   minheap.deleteKey(position);
                   minheap.status();
                   break;
            case 5:cout<<"Enter the value :\n";
                   int k;
                   cin>>k;
                   minheap.insertKey(k);
                   minheap.status();
                   break;
            default:cout<<"Invalid Choice \n";
                    break;
        }
    }
    return 0;
}
