//String Search
//Send Feedback
//Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
//Input format :
//
//Line 1 : String S
//
//Line 2 : String T
//
//Sample Input 1:
//WelcomeBack
//come 
//Sample Output 1:
//3
//Sample Input 2:
//WelcomeBack
//code
//Sample Output 2:
//-1


// S and T - input strings
// You need to check if string T is present in S or not

int*getlps(char pat[])
{
  int length;
    
  int i=0;
  while(pat[i]!='\0')
  {
      i++;
  }
  length=i;
  i=1;
  int*lps=new int[length];
  
  int j=0;
  lps[0]=0;
  while(i<length)
  {
      if(pat[i]==pat[j])
      {   
          lps[i]=j+1;
          i++;
          j++;
          
      }
      else
      {
          if(j!=0)
          {
             j=lps[j-1];
          }
          else
          {
              lps[i]=0;
              i++;
          }
          
      }
      
  }
  return lps;  

}


int findString(char S[], char T[]) {
    
      int i=0,j=0;
      
      int*lps=getlps(T);
      int resindex=0;
      
      while(S[i]!='\0'&&T[j]!='\0')
      {
          if(S[i]==T[j])
          {
              i++;
              j++;
          }
          else
          {
              if(j!=0)
              {
                j=lps[j-1];
              }
              else
              {
                  i++;
                  resindex=i;
              }
          }
              
          
      }
      
      if(T[j]=='\0')
          return resindex;
      else
          return -1;
    
    
    // Write your code here

}

