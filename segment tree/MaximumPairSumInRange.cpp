//Maximum Pair Sum
//Send Feedback
//You are given a sequence A[1], A[2], ..., A[N], ( 0 = A[i] = 10^8 , 2 = N = 10^5 ). There are two types of operations and they are defined as follows:
//Update:
//This will be indicated in the input by a 'U' followed by space and then two integers i and x.
//U i x, 1 = i = N, and x, 0 = x = 10^8.
//This operation sets the value of A[i] to x.

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int maximum;
    int smaximum;
    
};

void buildtree(int*arr,node*tree,int start,int end,int treenode)
{
    if(start==end)
    {
        tree[treenode].maximum=arr[start];
        tree[treenode].smaximum=INT_MIN;
        return;
    }
    int mid=(start+end)/2;
    
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);
    node left=tree[2*treenode];
    node right=tree[2*treenode+1];
    tree[treenode].maximum=max(left.maximum,right.maximum);
    
    tree[treenode].smaximum=min(max(right.maximum,left.smaximum),max(right.smaximum,left.maximum));
}


void update(int*arr,node*tree,int start,int end,int treenode,int index, int value)
{
    if(start==end)
    {
        arr[index]=value;
        tree[treenode].maximum=value;
        return;
    }
    int mid=(start+end)/2;
    if(mid<index)
    {
        update(arr,tree,mid+1,end,2*treenode+1,index,value);
    }
    else
    {
        update(arr,tree,start,mid,2*treenode,index,value);
    }
    
    node left=tree[2*treenode];
    node right=tree[2*treenode+1];
    
    tree[treenode].maximum=max(left.maximum,right.maximum);
    
    tree[treenode].smaximum=min(max(right.maximum,left.smaximum),max(right.smaximum,left.maximum));
}

node query(node*tree,int start,int end,int l,int r,int treenode)
{
    if(start>r||end<l)
    {
        node temp;
        temp.maximum=INT_MIN;
        temp.smaximum=INT_MIN;
        return temp;
    }
    if(start>=l && end<=r)
        return tree[treenode];
    
   int mid=(start+end)/2;
    
    node left=query(tree,start,mid,l,r,2*treenode);
    node right=query(tree,mid+1,end,l,r,2*treenode+1);
    
    node res;
    res.maximum=max(left.maximum,right.maximum);
    
    res.smaximum=min(max(right.maximum,left.smaximum),max(right.smaximum,left.maximum));
    
    return res;
}


int main() {
    int n;
    cin>>n;
    int*arr=new int [n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    node*tree=new node[3*n];
    buildtree(arr,tree,0,n-1,1);
    int q;
    cin>>q;
    
    while(q--)
    {
        char ch;
        int a,b;
        cin>>ch>>a>>b;
        
        if(ch=='Q')
        {node ans= query(tree,0,n-1,a-1,b-1,1);
           int sum=ans.maximum+ans.smaximum;
           cout<<sum<<endl;
           
            
        }
       else if(ch=='U')
         {
            update(arr,tree,0,n-1,1,a-1,b);
            
         }
    }
	// Write your code here
}
