//Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
//Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”
//
//Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”
//
//Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”
//
//Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”
//
//Alice: “How many different decodings?”
//
//Bob: “Jillions!”
//For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.


#include <bits/stdc++.h>
#include<math.h>
using namespace std;

int main()
{
 while(true)
 {   int mod=1000000007;
     string s;
     getline(cin,s);
     if(s[0]-'0'==0)
         break;
     int n=s.length();
     int*arr=new int[n];
     int i=0;
     for(;i<n;i++)
     {
         arr[i]=s[i]-'0';
        
     }
     
     int*output=new int[n+1];
     output[0]=1;
     output[1]=1;
  int found=0;
     for(int i=2;i<=n;i++)
     {
         if(arr[i-1]==0){   // see this part 
         //so this part is to handle 0 as for 0 there is no code and if there is 00 or 30 40 and 50 
		 //then even though we have code for 3 4 and 5 we dont have any code for 0 or 30 40 50 thats why the answer will be 0 as no alphabatic code possible
             if(arr[i-2]>2||arr[i-2]==0){
                 cout<<0<<endl;
                 found=1;break;
             }
             output[i]=output[i-2];
             continue ;
         }
         long long sum =output[i-1];
         if(arr[i-2]*10+arr[i-1]<=26 && arr[i-2]*10+arr[i-1]>=10)
             sum+=output[i-2];
        
         
         output[i]=sum%mod;
     }
  if(found==0)
    cout<<output[n-1]<<endl; 
 }
    return 0;
}

