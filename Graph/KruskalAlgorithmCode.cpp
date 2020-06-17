//Kruskal's Algorithm
//Send Feedback
//Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
//Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
//For printing MST follow the steps -
//1. In one line, print an edge which is part of MST in the format -
//v1 v2 w
//where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
//2. Print V-1 edges in above format in different lines.
//Note : Order of different edges doesn't matter.



#include <iostream>
#include<algorithm>
using namespace std;



class edge
{
   public: int src;
           int dest;
           int weight;
};


bool compare(edge e1,edge e2)
{
    return(e1.weight<e2.weight);
}

int getparent(int*parent,int index)
{
    if(index==parent[index])
        return index;
    
    int res=getparent(parent,parent[index]);
    
    return res;
}


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    
  edge*arr=new edge[E];
    
    for(int i=0;i<E;i++)
    {
      int s,d,we;
       cin>>s>>d>>we;
       
        arr[i].src=s;
        arr[i].dest=d;
        arr[i].weight=we;
    }
    sort(arr,arr+E,compare);
    
    int count=0;
    int*parent=new int[V];
    
    for(int i=0;i<V;i++)
        parent[i]=i;
    
    
    int i=0;
    while(count<V-1)
    {  int srcparent=getparent(parent,arr[i].src);
       int destparent=getparent(parent,arr[i].dest);
        
        if(srcparent!=destparent)
        {
         int start=min(arr[i].src,arr[i].dest);
         int end=max(arr[i].src,arr[i].dest);
        
         cout<<start<<" "<<end<<" "<<arr[i].weight<<endl;
          
         
             
          count=count+1;
          parent[destparent]=srcparent;
          
         }
        i=i+1;
    }
    
     

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */

  return 0;
}

