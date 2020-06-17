//Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
//While printing a triplet, print the smallest element first.
//That is, if a valid triplet is (6, 5, 10) print "5 6 10". 
//There is no constraint that out of 5 triplets which have to be printed on 1st line. 
//You can print triplets in any order, just be careful about the order of elements in a triplet.


// arr - input array
// size - size of array
// x - sum of triplets
#include<map>
#include<algorithm>
#include<utility>
#include<vector>
void FindTriplet(int arr[], int size, int x) {
    
     sort(arr,arr+size);
    
    
   
    
      vector<vector<int>>result;
      for(int i=0;i<size-2;i++)
      {
          
          int start=i+1;
          int end=size-1;
          while(start<end)
          {
              int sum=arr[start]+arr[end]+arr[i];
              if(sum<x)
              {
                  start++;
              }
              else if(sum>x)
              {  end--;
              }
              else
              {
              
                vector<int>triplet;
                  int count1=0,count2=0;
                for(int ptr=start;ptr<=end;ptr++)
                {
                    if(arr[start]==arr[ptr])
                        count1=count1+1;
                    else
                        break;
                }
                   for(int ptr=end;ptr>=start;ptr--)
                {
                    if(arr[end]==arr[ptr])
                        count2=count2+1;
                       else
                           break;
                }
                int combinations=count1*count2;
                if(arr[start]==arr[end])
                    combinations=((end-start+1)*(end-start))/2;
                
                for(int j=0;j<combinations;j++)
                
                    {
			        cout<<arr[i]<<" "<<arr[start]<<" "<<arr[end]<<endl;
				    
                     }
			        
                  
                  start=start+count1;
                  end=end-count2;
                
              }
              
                  
              
          }
      }
     
     
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */

}

