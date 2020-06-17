//You are given an array of positive integers as input. 
//Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
//Such a subsequence is known as bitonic subsequence. 
//A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
//Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.


 	
	int longestBitonicSubarray(int *input, int n) 
    {
        int *inc=new int[n];
        int*dec=new int[n];
        inc[0]=1;
        dec[n-1]=1;
        for(int i=1;i<n;i++)
        {inc[i] = 1;
           for(int j=i-1;j>=0;j--)
           {
              if(input[j]<input[i])
           {
               inc[i]=max(inc[i],1+inc[j]);
                
           }
               else
                   continue;
             
           }
        }
        
            for(int i=n-2;i>=0;i--)
            {dec[i]=1;
                for(int j=i+1;j<n;j++)
                {
                    if(input[j]<input[i])
                    {
                        dec[i]=max(dec[i],dec[j]+1);
                    }
                    else
                        continue;
                }
            }
            
            int*biton=new int[n];
            int maxs = -1;
            for(int i=0;i<n;i++)
            {
                maxs=max(maxs,((inc[i]+dec[i])-1));
            }
           return maxs;
        
		
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
     	
     	
     	
 	}
/*hint - find longest increasing subsequence and then logest decreasing subsequence at every position  and then add both to find th largest bitonic array*/

