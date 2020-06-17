//Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
//His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
//To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, 
//such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool check(long long dist,long long*arr,int c,int n)
{
    int count=1;
    long long lastposition=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]-lastposition>=dist)
        {   
            count++;
            lastposition=arr[i];
        }
        if(count==c)
            return true;
    }
    return false;
}


long long findMaxMinDist(long long start,long long end,long long *arr,int c,int n)
{
    if(start<=end)
    {
       long long  mid=start+((end-start)/2);
        if(check(mid,arr,c,n))
            return findMaxMinDist(mid+1,end,arr,c,n);
        else
            return findMaxMinDist(start,mid-1,arr,c,n);
        
    }
    else
        return end;
}


int main() {
int t;
    cin>>t;
   while(t--)
   {int c;
    int n;
    cin>>n>>c;
    long long *arr=new long long [n];
     for(int i=0;i<n;i++)
         cin>>arr[i];
     sort(arr,arr+n);
     
     long long start_dist=1;
     long long end_dist=arr[n-1]-arr[0];
     
     long long maxmindist=findMaxMinDist(start_dist,end_dist,arr,c,n);
    
      cout<<maxmindist<<endl;
       
   }
	// Write your code here
}
