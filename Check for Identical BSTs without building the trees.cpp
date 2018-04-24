// A C program to check for Identical BSTs without building the trees
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include<bits/stdc++.h>
using namespace std;
bool isSameBSTUtil(int a[], int b[], int n, int i1, int i2, int min, int max)
{
int j, k;

/* Search for a value satisfying the constraints of min and max in a[] and
	b[]. If the parent element is a leaf node then there must be some
	elements in a[] and b[] satisfying constraint. */
for (j=i1; j<n; j++)
	if (a[j]>min && a[j]<max)
		break;
for (k=i2; k<n; k++)
	if (b[k]>min && b[k]<max)
		break;

/* If the parent element is leaf in both arrays */
if (j==n && k==n)
	return true;

/* Return false if any of the following is true
	a) If the parent element is leaf in one array, but non-leaf in other.
	b) The elements satisfying constraints are not same. We either search
		for left child or right child of the parent element (decinded by min
		and max values). The child found must be same in both arrays */
if (((j==n)^(k==n)) || a[j]!=b[k])return false;


return isSameBSTUtil(a, b, n, j+1, k+1, a[j], max) && // Right Subtree
		isSameBSTUtil(a, b, n, j+1, k+1, min, a[j]); // Left Subtree
}

bool isSameBSTUtil1(int a[],int b[],int n,int i1,int i2,int minit,int maxit){
    int j,k;
    for(j=i1;j<n;j++)
        if(a[j]>minit&&a[j]<maxit)
            break;
    for(k=i2;k<n;k++)
        if(b[k]>minit&&b[k]<maxit)
            break;
    if(j==n&&k==n)
        return true;
    if (((j==n)^(k==n))||(a[j]!=b[k])) return false;
    //if (((j==n)^(k==n)) || a[j]!=b[k])return false;
    return isSameBSTUtil(a,b,n,j+1,k+1,a[j],maxit)&&isSameBSTUtil(a,b,n,j+1,k+1,minit,a[j]);
}
bool isSameBSTUtil2(int a[],int b[],int n,int i1,int i2){
        if(n==0||n==1) return 1;
    int j1,j2,k1,k2,tmpmxa=0,tmpmna=0,tmpmxb=0,tmpmnb=0;
    for(j1=i1+1;j1<n;j1++)
        if(a[i1]<a[j1]){
            tmpmxa=a[j1];
            break;
        }
    for(j2=i1+1;j2<n;j2++)
        if(a[i1]>a[j2]){
            tmpmna=a[j2];
            break;
        }
    for(k1=i2+1;k1<n;k1++)
        if(b[i2]<b[k1]){
            tmpmxb=b[k1];
            break;
        }
    for(k2=i2+1;k2<n;k2++)
        if(b[i2]>b[k2]){
            tmpmnb=b[k2];
            break;
        }
    if(tmpmxa==tmpmnb==tmpmna==tmpmxb==0)
        return 1;
    if(tmpmna==tmpmxa&&tmpmnb==tmpmxb)
        return isSameBSTUtil2(a,b,n,j1,k1)&&isSameBSTUtil2(a,b,n,j2,k2);
    else return false;
}
bool isSameBST(int a[], int b[], int n)
{
    return isSameBSTUtil2(a, b, 4, 0, 0);
}

// Driver program to test above functions
int main()
{
int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
int n=sizeof(a)/sizeof(a[0]);
printf("%s\n", isSameBST(a, b, n)?
			"BSTs are same":"BSTs not same");
return 0;
}
