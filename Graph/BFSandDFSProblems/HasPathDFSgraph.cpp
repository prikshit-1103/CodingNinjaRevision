//Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
//V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
//E is the number of edges present in graph G.


#include <iostream>
using namespace std;

void checkpath(int**graph,int n,bool*visited,int v1)
{
   for(int i=0;i<n;i++)
    {
        if(i==v1||visited[i])
            continue;
        if(graph[v1][i]==1)
        {  
             visited[i]=true;
             checkpath(graph,n,visited,i);
            
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    int**graph=new int*[V];
    for(int i=0;i<V;i++)
    {
       graph[i]=new int [V];
        for(int j=0;j<V;j++)
            graph[i][j]=0;
    }
    
    for(int i=0;i<E;i++)
    { int a,b;
        cin>>a>>b;
      graph[a][b]=1;
      graph[b][a]=1;
    }
    int v1,v2;
    cin>>v1>>v2;
    
    bool*visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
     visited[v1]=true;
    
     checkpath(graph,V,visited,v1);
     
     if(visited[v2])
         cout<<"true";
     else
         cout<<"false";
    
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */

  return 0;
}


