//Given an undirected and disconnected graph G(V, E), print its BFS traversal.
//Here you need to consider that you need to print BFS path starting from vertex 0 only.
//V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
//E is the number of edges present in graph G.
//Note : 1. Take graph input in the adjacency matrix.
//2. Handle for Disconnected Graphs as well


#include <iostream>

#include<queue>
using namespace std;



void print(int**graph,int V,bool*visited, int startindex)
{queue<int>q;
   
    
    q.push(startindex);
    visited[startindex]=true;
    while(!q.empty())
    {
        int node=q.front();
        for(int i=0;i<V;i++)
        {
            if(visited[i]||i==node)
            {
                continue;
            }
            if(graph[node][i]==1)
            {
                q.push(i);
                visited[i]=true;
                
            }
            
        }
        cout<<node<<" ";
        q.pop();
    }
    
}

int main() {
    int V, E;
    cin >> V >> E;
    
    int**graph=new int*[V];
    for(int i=0;i<V;i++)
    {
        graph[i]=new int[V];
        for(int j=0;j<V;j++)
            graph[i][j]=0;
    }
    
    for(int i=0;i<E;i++)
    {
        int f,s;
        cin>>f>>s;
        graph[f][s]=1;
        graph[s][f]=1;
    }
    bool*visited=new bool [V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    
    print(graph,V,visited,0);
    
    for(int i=1;i<V;i++)
    {
        if(!visited[i])
        {
           print(graph,V,visited,i); 
        }
    }
   
    
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */

  return 0;
}

