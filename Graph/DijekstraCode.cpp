//Dijkstra's Algorithm
//Send Feedback
//Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
//Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
//Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.


#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int getminvertex(int*dist,bool*visited,int n)
{
    int minvertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]&&(dist[i]<dist[minvertex]||minvertex==-1))
        {minvertex=i;
        }
    }
    return minvertex;
}


void dijekstra(int**edge,int n)
{
    bool*visited=new bool[n];
    int*dist=new int[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[0]=0;
    
    for(int i=1;i<n;i++)
    {
        int minvertex=getminvertex(dist,visited,n);
        
        visited[minvertex]=true;
        
        for(int j=0;j<n;j++)
        {
            if(edge[minvertex][j]!=0&&!visited[j])
            {
                if(dist[j]>edge[minvertex][j]+dist[minvertex])
                {
                    dist[j]=dist[minvertex]+edge[minvertex][j];
                }
            }
        }
        
    }
    
    for(int i=0;i<n;i++)
    {
       cout<<i<<" "<<dist[i]<<endl; 
    }
    
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    
  int**edge=new int*[V];
  for(int i=0;i<V;i++)
  {
      edge[i]=new int[V];
      for(int j=0;j<V;j++)
      {
          edge[i][j]=0;
      }
  }
   
   for(int i=0;i<E;i++)
   {
       int a,b,w;
       cin>>a>>b>>w;
       
       edge[a][b]=w;
       edge[b][a]=w;
       
   }
     
    dijekstra(edge,V);
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */

  return 0;
}

