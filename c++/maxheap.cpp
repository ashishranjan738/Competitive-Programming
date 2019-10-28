#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y){
    *x^=*y^=*x^=*y;
}
class MaxHeap{
    int *harr;
    int capacity,heap_size;
public:
    MaxHeap(int);
    void MaxHeapify(int);
    int parent(int i){return (i-1)/2;}
    int left(int i){return (2*i)+1;}
    int right(int i){return (2*i)+2;}
    int extractMax();
    void increaseKey(int ,int );
    int getMax(){return harr[0];}
    void deleteKey(int );
    void insertKey(int );
    void status();
    int hsize(){return heap_size;}
    void changeVal(int ,int );
};
MaxHeap::MaxHeap(int c){
    heap_size=0;
    capacity=c;
    harr=new int[capacity];
}
void MaxHeap::status(){
    cout<<"\nStatus :";
    for(int i=0;i<heap_size;i++){
        cout<<harr[i]<<" ";
    }
    cout<<endl;
}
void MaxHeap::insertKey(int key){
    if(capacity==heap_size){
        cout<<"Overflow\n";
        return;
    }
    heap_size++;
    int i=heap_size-1;
    harr[i]=key;
    while(i!=0 && harr[i]>harr[parent(i)]){
        swap(&harr[i],&harr[parent(i)]);
        i=parent(i);
    }
}
void MaxHeap::increaseKey(int pos,int new_val){
    if(pos>capacity || pos>heap_size-1){
        cout<<"Element not present \n";
        return;
    }
    harr[pos]=new_val;
    while(pos!=0 && harr[pos]>harr[parent(pos)]){
        swap(&harr[pos],&harr[parent(pos)]);
        pos=parent(pos);
    }
}
void MaxHeap::MaxHeapify(int pos){
    int l=left(pos);
    int r=right(pos);
    int biggest=pos;
    if(l<heap_size && harr[l]>harr[biggest])
        biggest=l;
    if(r<heap_size && harr[r]>harr[biggest])
        biggest=r;
    if(biggest!=pos){
        swap(&harr[biggest],&harr[pos]);
        MaxHeapify(biggest);
    }
}
void MaxHeap::deleteKey(int i){
    if(i>heap_size-1){
        cout<<"Element not present \n";
        return;
    }
    if(heap_size>1)
        increaseKey(i,INT_MAX);
    extractMax();

}
int MaxHeap::extractMax(){
   if(heap_size==0)
        return INT_MIN;
   if(heap_size==1){
        heap_size--;
        return harr[0];
   }
   else{
        int root=harr[0];
        harr[0]=harr[heap_size-1];
        heap_size--;
        MaxHeapify(0);
        return root;
   }
}
void MaxHeap::changeVal(int pos,int val){
    if(pos>heap_size-1){
        cout<<"Element not found \n";
        return;
    }
    if(harr[pos]<val)
        increaseKey(pos,val);
    else{
        harr[pos]=val;
        MaxHeapify(pos);
    }
}
int main(){
    int  n;
    cin>>n;
    int val;
    cin>>val;
    MaxHeap maxheap(n);
    for(int i=0;i<val;i++){
        int temp;
        cin>>temp;
        maxheap.insertKey(temp);
    }
    maxheap.status();
    //cout<<"Hello \n";
    while(1){
        cout<<"\nEnter the value to execute the function:\n1.Extract Max\n2.Change Value\n3.Show Max value\n4.Delete key\n5.Insert key\n";
        int t;
        cin>>t;
        switch(t){
            case 1:cout<<maxheap.extractMax();
                    maxheap.status();
                    break;
            case 2:int key,pos;
                   cout<<"Enter the position and value :";
                   cin>>pos>>key;
                   maxheap.changeVal(pos,key);
                   maxheap.status();
                   break;
            case 3:
                   maxheap.hsize()?cout<<maxheap.getMax()<<endl:cout<<"No Elements present \n";
                   maxheap.status();
                   break;
            case 4:cout<<"Enter the position \n";
                   int position;
                   cin>>position;
                   maxheap.deleteKey(position);
                   maxheap.status();
                   break;
            case 5:cout<<"Enter the value :\n";
                   int k;
                   cin>>k;
                   maxheap.insertKey(k);
                   maxheap.status();
                   break;
            default:cout<<"Invalid Choice \n";
                    break;
        }
    }
    return 0;
}
