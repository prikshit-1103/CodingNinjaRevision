//You are given a magrid S ( a magic grid ) having R rows and C columns. Each cell in this magrid has either a Hungarian horntail dragon that our intrepid hero has to defeat, 
//or a flask of magic potion that his teacher Snape has left for him. A dragon at a cell (i,j) takes away |S[i][j]| strength points from him, and a potion at a cell (i,j) 
//increases Harry's strength by S[i][j]. If his strength drops to 0 or less at any point during his journey, Harry dies, and no magical stone can revive him.
//Harry starts from the top-left corner cell (1,1) and the Sorcerer's Stone is in the bottom-right corner cell (R,C). 
//From a cell (i,j), Harry can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and
// he can not move outside the magrid. Harry has used magic before starting his journey to determine which cell contains what, 
// but lacks the basic simple mathematical skill to determine what minimum strength he needs to start with to collect the Sorcerer's Stone. Please help him once again.
//Input (STDIN)
//The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines,
//each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with S[i][j] < 0 contain dragons,
// others contain magic potions.
//Output (STDOUT):
//Output T lines, one for each case containing the minimum strength Harry should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).



#include <bits/stdc++.h>
using namespace std;

int findminhealth(int**grid,int si,int sj,int ei,int ej,int**output,int r,int c)
{
    if(si>r-1||sj>c-1)
        return INT_MAX;
    if(si==ei&&sj==ej)
        return 1;
    if(output[si][sj]>-1)
        return output[si][sj];
    
    int first =findminhealth(grid,si+1,sj,ei,ej,output,r,c);
    int second=findminhealth(grid,si,sj+1,ei,ej,output,r,c);
    
    int res= min(first,second)-grid[si][sj];
   
    if(res<1)
        res= 1;
 output[si][sj]=res;
        return res;
}


int main()
{int t;
 cin>>t;
 while(t--)
 {
     int r,c;
     cin>>r>>c;
     int**grid=new int*[r];
     for(int i=0;i<r;i++)
     {
         grid[i]=new int[c];
         for(int j=0;j<c;j++)
             cin>>grid[i][j];
     }
     int**output=new int*[r];
          for(int i=0;i<r;i++)
     {
         output[i]=new int[c];
         for(int j=0;j<c;j++)
            output[i][j]=-1;
     }
     int minhealth=findminhealth(grid,0,0,r-1,c-1,output,r,c);
         cout<<minhealth<<endl;
 }
    return 0;
}

