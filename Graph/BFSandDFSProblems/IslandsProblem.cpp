//An island is a small piece of land surrounded by water . 
//A group of islands is said to be connected if we can reach from any given island to any other island in the same group .
// Given N islands (numbered from 1 to N) and
//two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
//Constraints :
//1<=N<=100
//1<=M<=(N*(N-1))/2
//1<=u[i],v[i]<=N
//Input Format :
//Line 1 : Two integers N and M
//Line 2 : List u of size of M
//Line 3 : List v of size of M




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


int solve(int n,int m,vector<int>u,vector<int>v)
{
    int**edge=new int*[n];
    for(int i=0;i<n;i++)
    {
        edge[i]=new int[n];
        for(int j=0;j<n;j++)
            edge[i][j]=0;
    }
    
    for(int i=0;i<m;i++)
    {
        edge[u[i]-1][v[i]-1]=1;
        edge[v[i]-1][u[i]-1]=1;
        
    }
    
    bool*visited=new bool[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    
   vector<vector<int>>res;
    
    for(int i=0;i<n;i++)
    {
    if(!visited[i])
            { visited[i]=true;
             
              res.push_back(connected(edge,n,visited,i));
            }
    
     }
    return res.size();
    
	// Write your code here .
}
