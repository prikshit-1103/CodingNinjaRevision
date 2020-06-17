//Prims Algorithm




#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int getminvertex(int*weight,bool*visited,int n)
{
    int minvertex=-1;
    for(int i=0;i<n;i++)
    {
     if(!visited[i]&&(weight[i]<weight[minvertex]||minvertex==-1))
         minvertex=i;
    }
    return minvertex;
}

void prims(int**edges,int n)
{
    bool*visited=new bool[n];
    int*parent=new int [n];
    int*weight=new int[n];
    for(int i=0;i<n;i++)
    {
      
        weight[i]=INT_MAX;
    }
    parent[0]=-1;
    weight[0]=0;
    
    
    for(int i=1;i<n-1;i++)
    {
        int minvertex=getminvertex(weight,visited,n);
        visited[minvertex]=true;
        for(int j=0;j<n;j++)
        {
            if(edges[minvertex][j]!=0 && !visited[j])
            {
                if(weight[j]>edges[minvertex][j])
                {
                    weight[j]=edges[minvertex][j];
                    parent[j]=minvertex;
                }
            }
        }
    }
    
    for(int i=1;i<n;i++)
    {
        if(parent[i]<i)
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        else
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
    }
    
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  int**edges=new int*[V];
  for(int i=0;i<V;i++)
  {edges[i]=new int[V];
   for(int j=0;j<V;j++)
       edges[i][j]=0;
      
  
  }
  for(int i=0;i<E;i++)
  {
      int a,b,w;
      cin>>a>>b>>w;
      edges[a][b]=w;
      edges[b][a]=w;
      
  }
    
    prims(edges,V);
  return 0;
}

