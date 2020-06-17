//Horrible Queries
//Send Feedback
//World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, 
//now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, 
//which are initially all 0. After that you will be given C commands. They are -
//0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.
//
//1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
//Input
//In the first line you'll be given T, number of test cases.
//
//Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.


#include<bits/stdc++.h>
using namespace std;

void update(long long*tree,long long *lazy,long long*arr,int l,int r,long long value,int start,int end,int treenode)
{if(end<start)
      return;
 
   if(lazy[treenode]!=0)
   {
       tree[treenode]=tree[treenode]+(lazy[treenode]*(end-start+1));
       if(start!=end)
       {
           lazy[2*treenode]+=lazy[treenode];
           lazy[2*treenode+1]+=lazy[treenode];
       }
       lazy[treenode]=0;
   }
   
    
   if(start>r||end<l)
        return;
   if(start>=l && end<=r)
   {
       tree[treenode]=tree[treenode]+((end-start+1)*value);
       if(start!=end)
       {
           lazy[2*treenode]+=value;
           lazy[2*treenode+1]+=value;
       }
      
       return;
   }
   int mid=(start+end)/2;
   update(tree,lazy,arr,l,r,value,start,mid,2*treenode);
   update(tree,lazy,arr,l,r,value,mid+1,end,2*treenode+1);
    
    tree[treenode]=tree[treenode*2]+tree[2*treenode+1];
}


long long  query(long long *tree,long long *lazy,int l,int r,int start,int end,int treenode)
{
    if(lazy[treenode]!=0)
   {
       tree[treenode]=tree[treenode]+(lazy[treenode]*(end-start+1));
       if(start!=end)
       {
           lazy[2*treenode]+=lazy[treenode];
           lazy[2*treenode+1]+=lazy[treenode];
       }
       lazy[treenode]=0;
   }
    
   if(start>r||end<l)
       return 0;
   if(start>=l&&end<=r)
   return tree[treenode];
   
    int mid=(start+end)/2;
    long long left=query(tree,lazy,l,r,start,mid,2*treenode);
    long long right=query(tree,lazy,l,r,mid+1,end,2*treenode+1);
    
    long long  res=left+right;
    return res;
    
}


int main() {
int t;
    cin>>t;
    while(t--)
        {int n;
         cin>>n;
         long long*arr=new long long [n];
         long long *lazy=new long long[4*n];
         long long *tree=new long long[4*n];
         for(int i=0;i<n;i++)
             arr[i]=0;
         for(int i=0;i<4*n;i++)
         {
             lazy[i]=0;
             tree[i]=0;
         }
         int q;
         cin>>q;
         for(int i=0;i<q;i++)
             {int type;
              cin>>type;
              int p,q;
                   cin>>p>>q;
              if(type==0)
                  {int v;
                   cin>>v;
                   update(tree,lazy,arr,p-1,q-1,v,0,n-1,1);
                  
                  }
              else
                  {
                   long long  res1= query(tree,lazy,p-1,q-1,0,n-1,1);
                   cout<<res1<<endl;
                  
                  }
             
             }
  
        }
	// Write your code here
}
