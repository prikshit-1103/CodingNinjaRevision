//Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. 
//Edit Distance of two strings is minimum number of steps required to make one string equal to other. 
//In order to do so you can perform following three operations only :
//1. Delete a character
//
//2. Replace a character with another one
//
//3. Insert a character
//Note - Strings don't contain spaces
//Input Format :
//Line 1 : String s
//Line 2 : String t

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int edithelp(string s1,string s2,int l1,int l2,int**output)
{
    if(l2==0)
        return l1;
    if(l1==0)
        return l2;
    
    if(output[l1][l2]!=-1)
        return output[l1][l2];
    int result;
    
    if(s1.substr(0,1)==s2.substr(0,1))
        result=edithelp(s1.substr(1,l1-1),s2.substr(1,l2-1),l1-1,l2-1,output);
    else
    {
        int r1=1+edithelp(s1.substr(1,l1-1),s2.substr(1,l2-1),l1-1,l2-1,output);
        int r2=1+edithelp(s1.substr(1,l1-1),s2,l1-1,l2,output);
        int r3=1+edithelp(s1,s2.substr(1,l2-1),l1,l2-1,output);
        
        result=min(r1,min(r2,r3));
    }
      output[l1][l2]=result;
      return result;  
}

int editDistance(string s1, string s2){
    int l1=s1.length();
    int l2=s2.length();
    
    int**output=new int*[l1+1];
    for(int i=0;i<l1+1;i++)
    {
        output[i]=new int[l2+1];
        for(int j=0;j<l2+1;j++)
        {
            output[i][j]=-1;
        }
    }
    
    int res=edithelp(s1,s2,l1,l2,output);
    
    return res;

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */


}

