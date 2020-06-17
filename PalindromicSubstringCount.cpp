//Given a string S, count and return the number of substrings of S that are palindrome.
//Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
//Input Format :
//String S
//Output Format :
//count of palindrome substrings


int countPalindromeSubstrings(char s[]) {
    
    int i=0;
    while(s[i]!='\0')
    {
        i++;
    }
    int length=i;
    int count=0;
    for(i=0;i<length;i++)
    {
        int left=i;
        int right=i;
        
        while(left>=0&&right<length)
        {
            if(s[left]==s[right])
            {
                count=count+1;
                left=left-1;
                right=right+1;
            }
            else
                break;
        }
        
        left=i;
        right=i+1;
        
        
