//You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
//You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
//Best solution takes O(n) time.
//If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.



#include <vector>
#include<unordered_map>
#include<iostream>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	unordered_map<int,bool>input;
    unordered_map<int,int>checkindex;
    for(int i=0;i<n;i++)
    {
        input[arr[i]]=true;
        if(checkindex.find(arr[i])==checkindex.end())
        checkindex[arr[i]]=i;
    }
    int maxstart=0;
    int maxcount=0;
    int minindex=n;
    for(auto itr = input.begin();itr!=input.end();itr++)
    {  
        if(itr->second)
            { itr->second=false;
             
              int count=1;
              int start=itr->first;
              int search=itr->first+1;
             
             while(input.find(search)!=input.end())
             {  
                     
              
                 input[search]=false;
                 count++;
                 search=search+1;
             }
             search=itr->first-1;
             while(input.find(search)!=input.end())
             { 
              
                 input[search]=false;
                 count++;
                 start=start-1;
                 search=search-1;
             }
        
            
            if(maxcount<count)
             {
             maxcount=count;
               
             maxstart=start;
                
            
             }
            else if(maxcount==count)
            { if(checkindex[maxstart]>checkindex[start])
                  maxstart=start;
            }

        }
     
    }
    vector<int>result;
    for(int i=maxstart;i<maxcount+maxstart;i++)
    {
        result.push_back(i);
    }
    return result;
}
