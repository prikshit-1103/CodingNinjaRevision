//Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
//V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
//E is the number of edges present in graph G.
//You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
//Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.


#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> connected(int**edge,int V,bool*visited,int v1)
{vector<int>con;
 con.push_back(v1);
    for(int i=0;i<V;i++)
    {
        if(visited[i]||i==v1)
            continue;
        if(edge[v1][i]==1)
        {visited[i]=true;
         vector<int>smalloutput=connected(edge,V,visited,i);
        
         for(int i=0;i<smalloutput.size();i++)
             con.push_back(smalloutput[i]);
         
        }
    }
 return con;
}


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    int**edge=new int*[V];
    for(int i=0;i<V;i++)
    {edge[i]=new int[V];
        for(int j=0;j<V;j++)
            edge[i][j]=0;
    }
    for(int i=0;i<E;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a][b]=1;
        edge[b][a]=1;
            
    }
    bool*visited=new bool[V];
        for(int i=0;i<V;i++)
            visited[i]=false;
    
    vector<vector<int>>res;
    
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            { visited[i]=true;
              res.push_back(connected(edge,V,visited,i));
            }
    }
    for(int i=0;i<res.size();i++)
    {sort(res[i].begin(),res[i].end());
        for(int j=0;j<res[i].size();j++)
            
            
            cout<<res[i][j]<<" ";
        
        cout<<endl;
    }

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */

  return 0;
}

