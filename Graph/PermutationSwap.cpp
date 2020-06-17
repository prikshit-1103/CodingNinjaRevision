//Permutation Swaps
//Send Feedback
//Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.
//
//Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his permutation:
//
//Swap Px and Py only if (x, y) is a good pair.
//Help him and tell if Kevin can obtain permutation Q using such operations.
//Input format:
//The first line of input will contain an integer T, denoting the number of test cases.
//
//Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. 
//The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.
//Output format:
//For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.


#include<bits/stdc++.h>
using namespace std;

void dfs(bool*visited,vector<int>*edges,vector<int>&component,int start)
{  
    visited[start]=true;
    component.push_back(start);
    for(int i=0;i<edges[start].size();i++)
    { 
        int nextnode=edges[start][i];
        if(!visited[nextnode])
        {
            dfs(visited,edges,component,nextnode);
        }
        
    }
}


vector<vector<int>>findcomponents(bool*visited,vector<int>*edges,int n)
{
    vector<vector<int>>output;
    for(int i=1;i<=n;i++)
    { vector<int>component;  
        if(!visited[i])
        {    
            dfs(visited,edges,component,i);
        }
      if(component.size()>1)
       {
       output.push_back(component);
       }
    }
    
    return output;
}


bool compare(vector<int>p,vector<int>q)
{sort(p.begin(),p.end());
 sort(q.begin(),q.end());
 
 for(int i=0;i<p.size();i++)
 {
     if(p[i]!=q[i])
         return false;
 }
 
 return true;

}

int main()
{int t;
 cin>>t;
 while(t--)
 {
     int n,m;
     cin>>n>>m;
     int*p=new int[n+1];
     int*q=new int[n+1];
     for(int i=1;i<=n;i++)
         cin>>p[i];
     for(int i=1;i<=n;i++)
         cin>>q[i];
     
     
     vector<int>*edges=new vector<int>[n+1];
     for(int i=0;i<m;i++)
     {
         int a,b;
         cin>>a>>b;
         edges[a].push_back(b);
         edges[b].push_back(a);
     }
     
     
     
     bool*visited=new bool[n+1];
     
     for(int i=1;i<=n;i++)
         visited[i]=false;
     
     vector<vector<int>>components=findcomponents(visited,edges,n);
     int res=1;
     for(int i=0;i<components.size();i++)
     {
         vector<int>pvalue;
         vector<int>qvalue;
         for(int j=0;j<components[i].size();j++)
         {
             
             
             pvalue.push_back(p[components[i][j]]);
             qvalue.push_back(q[components[i][j]]);
             
         }
       if(!compare(pvalue,qvalue))
       {
           res=0;
           cout<<"NO"<<endl;
           break;
       }
           
         
     }
     
     
   if(res==1)
   {
       cout<<"YES"<<endl;
   }
     
 }
 
	//code
	return 0;
}

