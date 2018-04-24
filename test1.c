/*C program to sort a list of elements stored in an array data structure; using bubble sort, insertion sort, selection sort, quick sort, merge sort and heap sort techniques.*/
#include<stdio.h>
#include<math.h>
#define max 50
void swap(int*,int*);
void main()
{
    int ch,i,j,lb,ub,n,midindex,a[max],c[max],c1;
    char c2;
    void bublsort_non_rec(int[],int);
    void bubble_sort_rec(int[],int,int);
    void inssort_non_rec(int[],int);
    void insertion_sort_rec(int[],int,int);
    void selsort_non_rec(int[],int);
    void selection_sort_rec(int[],int,int);
    void quick_sort_rec(int[],int,int);
    void quick_sort_non_rec(int[],int,int);
    void m_sort_rec(int[],int,int);
    void mergesort_non_rec(int[],int,int);
    void heapsort(int[],int,int);
    while(1)
    {
        printf("Give number of data in the array : ");
        scanf("%d",&n);
        lb=0;
        ub=n-1;
        printf("Enter the elements of the array : ");
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("n.....Menu.....");
        printf("n1>Bubble sort.n2>Insertion sort.n3>Selection sortn4>Quicksort.n5>Mergesort.n6>HeapsortnEnter choice : ");
        scanf("n%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("n1>Non-recursive.n2>RecursivenEnter choice : ");
                scanf("%d",&c1);
                if(c1==1)
                    bublsort_non_rec(a,n);
                else if(c1==2)
                    bubble_sort_rec(a,lb,ub);
                else
                {
                    printf("Invalid choice givenn");
                    return;
                }
                break;
            }
            case 2:
            {
                printf("n1>Non-recursive.n2>RecursivenEnter choice : ");
                scanf("%d",&c1);
                if(c1==1)
                    inssort_non_rec(a,n);
                else if(c1==2)
                    insertion_sort_rec(a,lb,ub);
                else
                {
                    printf("Invalid choice givenn");
                    return;
                }
                break;
            }
            case 3:
            {
                printf("n1>Non-recursive.n2>RecursivenEnter choice : ");
                scanf("%d",&c1);
                if(c1==1)
                    selsort_non_rec(a,n);
                else if(c1==2)
                    selection_sort_rec(a,lb,ub);
                else
                {
                    printf("Invalid choice givenn");
                    return;
                }
                break;
            }
            case 4:
            {
                printf("n1>Non-recursive.n2>RecursivenEnter choice : ");
                scanf("%d",&c1);
                if(c1==1)
                    quick_sort_non_rec(a,lb,ub);
                else if(c1==2)
                    quick_sort_rec(a,lb,ub);
                else
                {
                    printf("Invalid choice givenn");
                    return;
                }
                break;
            }
            case 5:
            {
                printf("n1>Non-recursiven2>RecursivenEnter choice : ");
                scanf("%d",&c1);
                if(c1==1)
                    mergesort_non_rec(a,lb,ub);
                else if(c1==2)
                    m_sort_rec(a,lb,ub);
                else
                {
                    printf("Invalid choice givenn");
                    return;
                }
                break;
            }
            case 6:
            {
                heapsort(a,lb,ub);
                break;
            }
            default:
            {
                printf("Invalid choice givenn");
                return;
            }
        }
        printf("nThe sorted array is : n");
        for(i=0;i<n;i++)
            printf("%dt",a[i]);
        printf("n");
        printf("Do you want to sort a new set of data(Y/N):");
        scanf(" %c",&c2);
        switch(c2)
        {
            case 'y':
            case 'Y':break;
            case 'n':
            case 'N':printf("You have chosen to exit from the program.n");
                return;
            default: printf("nINVALID CHOICE!!!!n");
                return;
        }
        printf(".....Enter a new set of data.....n");
    }
}
/*Non recursive bubble sort*/
void bublsort_non_rec(int a[],int n)
{
    int i,j,f;
    void swap(int*,int*);
    for(i=1,f=0;i<=n-1;i++)
    {
/*compare elements side by side and move highest element of unsorted part to start of sorted part*/
        for(j=0;j<=n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
                f=1;
            }
        }
        if(f=0)/*stop unnecessary looping if the list is already sorted*/
            break;
    }

}
/*This function swaps two elements passed as parameters*/
void swap(int*p,int*q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
/*Non recursive insertion sort*/
void inssort_non_rec(int a[],int n)
{
    int i,j,key;
    for(i=1;i<=n-1;i++)
    {
/*insert a[i] into the sorted sequence a[lb]..a[i-1]*/
        key=a[i];
        for(j=i-1;j>=0&&a[j]>key;j--)
            a[j+1]=a[j];
        a[j+1]=key;
    }

}
/*Non recursive selection sort*/
void selsort_non_rec(int a[],int n)
{
    int i,j,max_index,temp;
    for(i=n-1;i>0;i--)
    {
/*find the maximum in a[lb]..a[i] */
        max_index=i;
        for(j=0;j<i;j++)
            if(a[j]>a[max_index])
                max_index=j;
        if(i!=max_index)/*swap the maximum of a[lb]..a[i] with a[i] if they are different*/
            swap(&a[i],&a[max_index]);
    }
}
/* This algorithm partition the list into two parts with respect to a pivot element, so that the elements of left and right partition of pivot are less than and greater than or equal to the pivot element respectively*/
int partition(int lb,int ub,int a[])
{
    int i,j;
    for(i=lb,j=lb+1;j<=ub;j++)
        if(a[lb]>a[j])
            swap(&a[++i],&a[j]);
    swap(&a[lb],&a[i]);
    return i;
}
/*Recursive quick sort*/
void quick_sort_rec(int a[],int lb,int ub)
{
    int p;
    int partition(int,int,int[]);
/*check for empty or single element list*/
    if(lb>=ub)
        return;/*stop recursion*/
    p=partition(lb,ub,a);/*partition the list*/
    quick_sort_rec(a,lb,p-1);/*continue recursion for left partition*/
    quick_sort_rec(a,p+1,ub);/*continue recursion for right partition*/
}
/*Recursive merge sort*/
void m_sort_rec(int a[],int lb,int ub)
{
    int mid;
    void merge(int[],int,int,int);
    if(lb>=ub)
        return;/*Stop recursion*/
    mid=(lb+ub)/2;
    m_sort_rec(a,lb,mid);/*Self-calling*/
    m_sort_rec(a,mid+1,ub);/*Self-calling*/
    merge(a,lb,mid,ub);
}
/*merge two sorted sub lists into one sorted list*/
void merge(int a[],int lb,int mid,int ub)
{
    int i,j,k,tmp[50];
    for(i=lb,j=mid+1,k=lb;i<=mid&&j<=ub;k++)
    {
        if(a[i]>=a[j])
        {
            tmp[k]=a[j];
            j++;
        }
        else
        {
            tmp[k]=a[i];
            i++;
        }

    }
    while(j<=ub)
    {
        tmp[k]=a[j];
        j++;
        k++;
    }
    while(i<=mid)
    {
        tmp[k]=a[i];
        i++;
        k++;
    }
    for(k=lb;k<=ub;k++)
        a[k]=tmp[k];
}
/*Non recursive heap sort*/
void heapsort(int a[],int lb,int ub)
{
    int i;
    void create_heap(int[],int,int,int,int);
    void del_heap(int[],int,int,int);
    for(i=lb;i<=ub;i++)
    {
        create_heap(a,i,a[i],lb,ub);/*Heap-creation with input elements*/
    }
    i=ub;
    while(i>=lb)
    {
        del_heap(a,i+1,lb,ub);/*Deletion from heap is always in descending order*/
        i--;
    }
}
/*Function to create a heap with input elements*/
void create_heap(int a[],int heapsize,int data,int lb,int ub)
{
    int i,p;
    int parent(int);
    i=lb+heapsize;
    a[i]=data;
    while(i>lb&&a[p=parent(i)]<a[i])
    {
        swap(&a[p],&a[i]);
        i=p;
    }
}
/*Function to delete elements from previously created heap*/
void del_heap(int a[],int heapsize,int lb,int ub)
{
    int data,i,l,r,max_child;
    int left(int);
    int right(int);
    swap(&a[lb],&a[heapsize-1]);
    i=lb;
    heapsize--;
    while(1)
    {
        if((l=left(i))>=heapsize)
            break;
        if((r=right(i))>=heapsize)
            max_child=l;
        else
            max_child=(a[l]>a[r])?l:r;
        if(a[i]>=a[max_child])
            break;
        swap(&a[i],&a[max_child]);
        i=max_child;
    }
}
/*This function returns parent index of an element in the list*/
int parent(int i)
{
    float p;
    p=((float)i/2.0)-1.0;
    return ceil(p);
}
/*This function returns left child index of an element in the list*/
int left(int i)
{
    return 2*i+1;
}
/*This function returns right child index of an element in the list*/
int right(int i)
{
    return 2*i+2;
}
/*Recursive bubble sort*/
void bubble_sort_rec(int a[],int lb,int ub)
{
    int j,f;
    if(lb>=ub)/*Check for terminating condition*/
        return;
/*compare elements side by side and move highest element to the end*/
    for(j=lb,f=0;j<=lb+ub-1;j++)
    {
        if(a[j]>a[j+1])
        {
            swap(&a[j],&a[j+1]);
            f=1;
        }
    }
/*Continue recursion if the list is not yet sorted*/
    if(f=1)
        bubble_sort_rec(a,lb,ub-1);/*Self calling*/
}
/*Recursive insertion sort*/
void insertion_sort_rec(int a[],int lb,int ub)
{
    int j,key;
    if(lb>=ub)/*Check for terminating condition*/
        return;
    insertion_sort_rec(a,lb,ub-1);/*Self calling*/
/*Insert a[ub] into the sorted sequence a[lb]..a[ub-1]*/
    key=a[ub];
    for(j=ub-1;j>=lb && a[j]>key;j--)
        a[j+1]=a[j];
    a[j+1]=key;
}
/*Recursive selection sort*/
void selection_sort_rec(int a[],int lb,int ub)
{
    int j,max_index;
    if(lb>=ub)/*Check for terminating condition*/
        return;
/*Find the maximum in a[lb]..a[ub]*/
    max_index=ub;
    for(j=0;j<ub;j++)
    {
        if(a[j]>a[max_index])
            max_index=j;
    }
/*Swap the maximum of a[lb]..a[ub] with a[ub] if they are different*/
    if(ub!=max_index)
        swap(&a[ub],&a[max_index]);
    selection_sort_rec(a,lb,ub-1);/*Self calling*/
}
/*Non recursive merge sort*/
void mergesort_non_rec(int a[],int lb,int ub)
{
    int k,i;
    int min(int,int);
    for(k=1;k<=(ub-lb+1);k*=2)
    {
        for(i=lb;i<=(ub-k);i+=2*k)
            merge(a,i,(i+k-1),min((i+2*k-1),ub));/*Every two adjacent blocks are merged*/
    }
}
/*This function returns minimum of two elements*/
int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}
/*Non recursive quick sort*/
void quick_sort_non_rec(int a[],int lb,int ub)
{
    int stack[max],p,top=0;
    void push(int[],int,int*);
    int pop(int[],int*);
    int stack_empty(int*);
    push(stack,lb,&top);
    push(stack,ub,&top);
    while(stack_empty(&top)==0)/*This loop will continue until stack is empty*/
    {
/*Initialize the current sub list*/
        ub=pop(stack,&top);
        lb=pop(stack,&top);
/*check for empty or single element sub list*/
        if(lb>=ub)
            continue;
/*Partition the sub list*/
        p=partition(lb,ub,a);
/*Set the left partition*/
        push(stack,lb,&top);
        push(stack,p-1,&top);
/*Set the right partition*/
        push(stack,p+1,&top);
        push(stack,ub,&top);
    }
}
/*Function to insert elements into stack*/
void push(int stack[],int data,int* top)
{
    if(*top>=max)
    {
        printf("Error overflow.n");
        return;
    }
    stack[*top]=data;
    (*top)++;
}
/*Function to delete elements from stack*/
int pop(int stack[],int *top)
{
    int data;
    (*top)--;
    data=stack[*top];
    return data;
}
/*This function returns 1 if stack is empty else returns 0*/
int stack_empty(int *top)
{
    if(*top==0)
        return 1;
    else
        return 0;
}
