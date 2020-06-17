//You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}.
// You need to figure out the total number of ways W, 
// in which you can make change for Value V using coins of denominations D.


int counthelper(int*denominations,int num,int value,int**output)
{
    if(value==0)
        return 1;
    
    if(value<0)
        return 0;
    
    if(num==0)
        return 0;
    
    if(output[value][num]>-1)
        return output[value][num];
    
    int first  = counthelper(denominations,num,value-denominations[0],output);
    int second =counthelper(denominations+1,num-1,value,output);//array passing recursively
    
    output[value][num]=first+second;
    return first+second;
    
}


int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    
    int**output=new int*[value+1];
    for(int i=0;i<value+1;i++)
    {
        output[i]= new int[numDenominations+1];
        for(int j=0;j<numDenominations+1;j++)
            output[i][j]=-1;
    }
    
  
    int res = counthelper(denominations,numDenominations,value,output);
    
    
  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */


}

