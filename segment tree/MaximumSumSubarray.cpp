//Maximum Sum In Subarray
//Send Feedback
//You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| = 15007 , 1 = N = 50000 ). A query is defined as follows:
//Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x = i = j = y }.
//Given M queries, your program must output the results of these queries.
//Input
//The first line of the input file contains the integer N.
//In the second line, N numbers follow.
//The third line contains the integer M.
//M lines follow, where line i contains 2 numbers xi and yi.

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct node
{long  sum;
 long  maxsum;
 long  pref_sum;
 long  suf_sum;
    
};
void buildtree(int*arr,node*tree,int start,int end,int treenode)
{
 if(start==end)
 {
     tree[treenode].sum=arr[start];
     tree[treenode].maxsum=arr[start];
     tree[treenode].pref_sum=arr[start];
     tree[treenode].suf_sum=arr[start];
     return;
 }
 int mid=(start+end)/2;
 
  buildtree(arr,tree,start,mid,2*treenode);
  buildtree(arr,tree,mid+1,end,2*treenode+1);
    
  node left=tree[2*treenode];
  node right=tree[2*treenode+1];
    
  tree[treenode].sum=left.sum+right.sum;
  tree[treenode].pref_sum=max(left.pref_sum,left.sum+right.pref_sum);
  tree[treenode].suf_sum=max(right.suf_sum,right.sum+left.suf_sum);
  tree[treenode].maxsum=max(max(left.maxsum,right.maxsum),max(left.suf_sum+right.pref_sum,max(left.sum+right.pref_sum,right.sum+left.suf_sum)));
}

node query(node*tree,int start,int end,int x,int y,int treenode)
{ node res;
 if(start>y||end<x)
 {
    
     res.maxsum=INT_MIN;
     res.sum=INT_MIN;
     res.pref_sum=INT_MIN;
     res.suf_sum=INT_MIN;
     return res;
 }
if(start>=x&&end<=y)
{
    return tree[treenode];
}

    int mid=(start+end)/2;
    node left=query(tree,start,mid,x,y,2*treenode);
    node right=query(tree,mid+1,end,x,y,2*treenode+1);
     
  res.sum=left.sum+right.sum;
  res.pref_sum=max(left.pref_sum,left.sum+right.pref_sum);
  res.suf_sum=max(right.suf_sum,right.sum+left.suf_sum);
  res.maxsum=max(max(left.maxsum,right.maxsum),max(left.suf_sum+right.pref_sum,max(left.sum+right.pref_sum,right.sum+left.suf_sum)));
 
  return res;


    
}


int main() {
    int n,m;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    node*tree=new node[4*n];
    
    buildtree(arr,tree,0,n-1,1);
    cin>>m;
    for(int k=0;k<m;k++)
    {
        int x, y;
        cin>>x>>y;
        node res= query(tree,0,n-1,x-1,y-1,1);
        cout<<res.maxsum<<endl;
    }
    

	// Write your code here
}
