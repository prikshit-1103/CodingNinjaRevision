//Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and 
//(V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in 
//which (P,Q), (Q,R) and (R,P) are connected an edge.
//Input Format :
//Line 1 : Two integers N and M
//Line 2 : List u of size of M
//Line 3 : List v of size of M

int solve(int n,int m,vector<int>u,vector<int>v)
{int**edge=new int*[n];
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
    
   int res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(k==i)
                    continue;
                if(edge[i][j]&&edge[j][k]&&edge[k][i])
                    res=res+1;
            }
        }
    }
    
	return res/6;// Write your code here .
}
