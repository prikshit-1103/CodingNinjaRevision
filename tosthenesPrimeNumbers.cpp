//Find Prime Numbers From 1 to N

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool*arr=new bool[n+1];
    arr[1]=false;
    arr[0]=false;
    for(int i=2;i<=n;i++)
    {
        arr[i]=true;
    }
    
    int squareroot=sqrt(n);
    for(int i=2;i<=squareroot;i++)
    {
        for(long long j=i*i;j<=n;j=j+i)
        {
            arr[j]=false;
        }
    }
    long long count=0;
    for(int i=0;i<=n;i++)
    {
        if(arr[i])
            count++;
            
    }
    cout<<count<<endl;
    delete[] arr;
	// Write your code here
	return 0;
}
