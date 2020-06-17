//Range Minimum Query
//Given an array A of size N, there are two types of queries on this array.
//1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
//2) u x y: In this query you need to update A[x]=y.
//Input:
//First line of the test case contains two integers, N and Q, size of array A and number of queries.
//Second line contains N space separated integers, elements of A.
//Next Q lines contain one of the two queries.



#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#include<string>

void createtree(int*arr,int*tree,int start,int end,int treenode)
{
    if(start==end)
    {
        tree[treenode]=arr[start];
        return;
    }
    
    int mid=start+((end-start)/2);
    createtree(arr,tree,start,mid,2*treenode);
    createtree(arr,tree,mid+1,end,2*treenode+1);
    
    tree[treenode]=min(tree[2*treenode],tree[2*treenode+1]);
}

void update(int*arr,int*tree,int start,int end,int treenode,int index,int value)
{
    if(start==end)
    {
        arr[index]=value;
        tree[treenode]=value;
        return;
    }
    int mid=(start+end)/2;
    if(mid<index)
    {
        update(arr,tree,mid+1,end,2*treenode+1,index,value);
    }
    else
        update(arr,tree,start,mid,2*treenode,index,value);
    
    tree[treenode]=min(tree[2*treenode],tree[2*treenode+1]);
}

int  query(int*tree,int start,int end,int l,int r,int treenode)
{
    if(r<start||l>end)
        return INT_MAX;
    if(l<=start&&end<=r)
    {
        return tree[treenode];
    }
    int mid=(start+end)/2;
    int b=query(tree,start,mid,l,r,2*treenode);
    
    int a =query(tree,mid+1,end,l,r,2*treenode+1);
    
    return min(a,b);
}


int main() {int n,q;
            cin>>n>>q;
            int*arr=new int[n];
            for(int i=0;i<n;i++)
            {
              cin>>arr[i];
            }
       int*tree=new int[4*n];
       
       createtree(arr,tree,0,n-1,1);
       while(q--)
       {char qr;
        int a,b;
        cin>>qr>>a>>b;
        
        if(qr=='q')
        {
          int q=query(tree,0,n-1,a-1,b-1,1);
          cout<<q<<endl;
        }
        else if(qr=='u')
        { update(arr,tree,0,n-1,1,a-1,b);
        
        }
       }
            
      
	// Write your code here
}
