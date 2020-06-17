//Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists).
// Print nothing if there is no path between v1 and v2.
//Find the path using BFS and print the shortest path available.
//V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
//E is the number of edges present in graph G.
//Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
//Note : Save the input graph in Adjacency Matrix.



#include <iostream>
#include<unordered_map>
#include<queue>

using namespace std;


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
    
    cin>>tempX>>tempY;
    unordered_map<int,int>map;
    map[tempY]=-1;
    bool*visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    queue<int>q;
    q.push(tempX);
    map[tempX]=tempX;
    visited[tempX]=true;
    while(!q.empty())
    { int x=q.front();
      q.pop(); 
      if(map[tempY]!=-1)
      {
          break;
      }
      
     
      for(int i=0;i<V;i++)
      {   if(i==x)
          continue;
          if(edge[x][i]==1&&!visited[i])
          {   visited[i]=true;
              q.push(i);
              map[i]=x;
          }
      
     
      }      
     }
    if(map[tempY]==-1)
        cout<<" ";
    else
    {cout<<tempY<<" ";
    int i=tempY;
    while(i!=tempX)
        {
           cout<<map[i]<<" ";
           i=map[i];
         }
    }
    
    

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */

  return 0;
}

