//Largest Piece
//Send Feedback
//Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . 
//But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge 
//with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
//Constraints :
//1<=N<=50
//Input Format :
//Line 1 : An integer N denoting the size of cake 
//Next N lines : N characters denoting the cake


int arr[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int used[200][200];


bool isvalid(int x,int y,int n)
{
    return(x<n&&x>=0&&y<n&&y>=0);
}

int findcount(char cake[NMAX][NMAX],int n,int x,int y)
{if(cake[x][y]!='1')
    return 0;
 
  int count=1;
  used[x][y]=1;
 for(int i=0;i<4;i++)
 {
     int newx=x+arr[i][0];
     
     int newy=y+arr[i][1];
     
     if(isvalid(newx,newy,n)&&!used[newx][newy])
     {count=count+findcount(cake,n,newx,newy);
     }
 }
 
  return count;
    
}

int solve(int n,char cake[NMAX][NMAX])
{int count=0;
    
for(int i=0;i<n;i++)
    {for(int j=0;j<n;j++)
        {int smallcount=0;
        if(cake[i][j]=='1')
        {smallcount=smallcount+findcount(cake,n,i,j);
        }
         
          count=max(smallcount,count);
        }
    
    }
 return count;
 
	// Write your code here .
}
