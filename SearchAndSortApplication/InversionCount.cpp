//Let A[0 ... n-1] be an array of n distinct positive integers.
// If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). 
//Given an integer array A, your task is to find the number of inversions in A

long long mergecount(int A[],int start,int mid,int end)
{int n1=mid-start+1;
 int n2=end-mid;
    long long count=0;
    long long *left=new long long [n1];
    long long *right=new long long [n2];
  
 for(int i=0;i<n1;i++)
 {
     left[i]=A[start+i];
 }
 for(int i=0;i<n2;i++)
 {
     right[i]=A[mid+1+i];
 }
 int leftptr=0;
 int rightptr=0;
 int k=start;
 
 while(leftptr<n1 && rightptr<n2)
 {
     if(left[leftptr]<=right[rightptr])
     {A[k]=left[leftptr];
      
      leftptr++;
     }
     else
     {  A[k]=right[rightptr];
        count=count+n1-leftptr;
        rightptr++; 
     }   
     k++;
 }
 while(leftptr<n1)
 {
     A[k]=left[leftptr];
     k++;
     leftptr++;
 }
 while(rightptr<n2)
 {
     A[k]=right[rightptr];
     k++;
     rightptr++;
 }
     
 return count;   
}



long long solvehelper(int A[],int start,int end)
{
    if(start<end)
    {   int mid=start+((end-start))/2;
        long long leftcount=solvehelper(A,start,mid);
        long long rightcount=solvehelper(A,mid+1,end);
        
        return (mergecount(A,start,mid,end)+leftcount+rightcount);
    }
    return 0;
}



long long solve(int A[], int n)
{
	int start=0;
    int end=n-1;
    return solvehelper(A,start,end);// Write your code here.
}
