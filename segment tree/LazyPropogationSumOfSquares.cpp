//Sum Of Squares
//Send Feedback
//Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
//The sum of squares over a range with range updates of 2 types:
//1) increment in a range
//2) set all numbers the same in a range.
//Input
//There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
//The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:
//
//2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).
//
//1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
//
//0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).


#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int ss;
    int s;
};
class Node{
  public:
    int set;
    int update;
};
void buildTree(int*arr,node*tree,int start,int end,int treeIndex){
    if(start==end){
        tree[treeIndex].s=arr[start];
        tree[treeIndex].ss=arr[start]*arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeIndex);
    buildTree(arr,tree,mid+1,end,2*treeIndex+1);
    tree[treeIndex].s=tree[2*treeIndex].s+tree[2*treeIndex+1].s;
    tree[treeIndex].ss=tree[2*treeIndex].ss+tree[2*treeIndex+1].ss;
}
void update(node*tree,Node*lazy,int type,int start,int end,int treeIndex,int left,int right,int v){
    if(start>end)
        return;
    if(lazy[treeIndex].set!=0){
        int x=lazy[treeIndex].set;
        tree[treeIndex].ss=x*x*(end-start+1);
        tree[treeIndex].s=x*(end-start+1);
        if(start!=end){
            lazy[2*treeIndex].set=x;
            lazy[2*treeIndex].update=0;
            lazy[2*treeIndex+1].set=x;
            lazy[2*treeIndex+1].update=0;
        }
        lazy[treeIndex].set=0;
    }
    if(lazy[treeIndex].update!=0){
        int x=lazy[treeIndex].update;
        tree[treeIndex].ss+=(x*x*(end-start+1))+(2*x*tree[treeIndex].s);
        tree[treeIndex].s+=x*(end-start+1);
        if(start!=end){
            lazy[2*treeIndex].update+=x;
            lazy[2*treeIndex+1].update+=x;
        }
        lazy[treeIndex].update=0;
    }
    if(end<left||right<start){
        return; 
   }
    if(start>=left&&end<=right){
        if(type==0){
            tree[treeIndex].ss=v*v*(end-start+1);
            tree[treeIndex].s=v*(end-start+1);
            if(start!=end){
                lazy[2*treeIndex].set=v;
                lazy[2*treeIndex].update=0;
                lazy[2*treeIndex+1].set=v;
                lazy[2*treeIndex+1].update=0;
            }
        }else{
            tree[treeIndex].ss+=(v*v*(end-start+1))+(2*v*tree[treeIndex].s);
            tree[treeIndex].s+=v*(end-start+1);
            if(start!=end){
                lazy[2*treeIndex].update+=v;
                lazy[2*treeIndex+1].update+=v;
            }
        }
        return;
    }
    int mid=(start+end)/2;
    update(tree,lazy,type,start,mid,2*treeIndex,left,right,v);
    update(tree,lazy,type,mid+1,end,2*treeIndex+1,left,right,v);
    tree[treeIndex].s=tree[2*treeIndex].s+tree[2*treeIndex+1].s;
    tree[treeIndex].ss=tree[2*treeIndex].ss+tree[2*treeIndex+1].ss;
}
int query(node*tree,Node*lazy,int start,int end,int treeIndex,int left,int right){
    if(start>end)
        return 0;
    if(lazy[treeIndex].set!=0){
        int x=lazy[treeIndex].set;
        tree[treeIndex].ss=x*x*(end-start+1);
        tree[treeIndex].s=x*(end-start+1);
        if(start!=end){
            lazy[2*treeIndex].set=x;
            lazy[2*treeIndex].update=0;
            lazy[2*treeIndex+1].set=x;
            lazy[2*treeIndex+1].update=0;
        }
        lazy[treeIndex].set=0;
    }
    if(lazy[treeIndex].update!=0){
        int x=lazy[treeIndex].update;
        tree[treeIndex].ss+=(x*x*(end-start+1))+(2*x*tree[treeIndex].s);
        tree[treeIndex].s+=x*(end-start+1);
        if(start!=end){
            lazy[2*treeIndex].update+=x;
            lazy[2*treeIndex+1].update+=x;
        }
        lazy[treeIndex].update=0;
    }
    if(end<left||right<start){
        return 0; 
    }
    if(start>=left&&end<=right){
        return tree[treeIndex].ss;
    }
    int mid=(start+end)/2;
    int ans1=query(tree,lazy,start,mid,2*treeIndex,left,right);
    int ans2=query(tree,lazy,mid+1,end,2*treeIndex+1,left,right);
    return ans1+ans2;
}
int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<":"<<endl;
        int n,q;
        cin>>n>>q;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        node tree[4*n];
        buildTree(arr,tree,0,n-1,1);
        Node lazy[4*n];
        for(int j=0;j<4*n;j++){
            lazy[j].set=0;
            lazy[j].update=0;
        }
        while(q--){
            int type;
            cin>>type;
            if(type==0||type==1){
                int l,r,v;
                cin>>l>>r>>v;
                update(tree,lazy,type,0,n-1,1,l-1,r-1,v);
            }else if(type==2){
                int l,r;
                cin>>l>>r;
               // cout<<"HI"<<endl;
                cout<<query(tree,lazy,0,n-1,1,l-1,r-1)<<endl;
            }
        }
    }
}
