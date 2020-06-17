//Counting Even/Odd
//Send Feedback
//Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
//Query 0 :- modify the element present at index i to x.
//Query 1:- count the number of even numbers in range l to r inclusive.
//Query 2:- count the number of odd numbers in range l to r inclusive.


#include<bits/stdc++.h>
using namespace std;
struct node
{int evencount;
 int oddcount;
    
};

void buildtree(int*arr,node*tree,int start,int end,int treenode)
{
    if(start==end)
    {
        if(arr[start]%2==0)
        {tree[treenode].evencount=1;
         tree[treenode].oddcount=0;
        }
        
        else
        { tree[treenode].oddcount=1;
          tree[treenode].evencount=0;
        }
        
        return;
    }
    int mid=(start+end)/2;
    
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);
    
    node left=tree[2*treenode];
    node right=tree[2*treenode+1];
    
    tree[treenode].evencount=left.evencount+right.evencount;
    tree[treenode].oddcount=left.oddcount+right.oddcount;
    
}
void update(int*arr,node*tree,int start,int end,int index,int value,int treenode)
{
    if(start==end)
    {
    
        arr[index]=value;
        if(value%2==0)
        {tree[treenode].evencount=1;
            tree[treenode].oddcount=0;
        }
        else
        {tree[treenode].oddcount=1;
         tree[treenode].evencount=0;
        }
        
        return;
    }
    int mid=(start+end)/2;
    if(index>mid)
        update(arr,tree,mid+1,end,index,value,2*treenode+1);
    else
        update(arr,tree,start,mid,index,value,2*treenode);
    
    
    node left=tree[2*treenode];
    node right=tree[2*treenode+1];
    tree[treenode].evencount=left.evencount+right.evencount;
    tree[treenode].oddcount=left.oddcount+right.oddcount;
}


node query(node*tree,int start,int end,int l,int r,int treenode)
{
    node res;
    if(start>r||end<l)
    {
       res.evencount=0;
       res.oddcount=0;
        return res;
    }
    if(start>=l&&end<=r)
    {
        return tree[treenode];
    }
    int mid=(start+end)/2;
    node left=query(tree,start,mid,l,r,2*treenode);
    node right=query(tree,mid+1,end,l,r,2*treenode+1);
    
     res.evencount=left.evencount+right.evencount;
     res.oddcount=left.oddcount+right.oddcount;
    
    return res;
    
}

int main() {
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   node*tree=new node[3*n]; 
    buildtree(arr,tree,0,n-1,1);
    
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {int type,x,y;
        cin>>type>>x>>y;
     if(type==0)
     {
        
         update(arr,tree,0,n-1,x-1,y,1);
         
     }
     else
     {node res=query(tree,0,n-1,x-1,y-1,1);
         if(type==1)
          cout<<res.evencount<<endl;
        else
          cout<<res.oddcount<<endl;}
    }
    
	// Write your code here
}
