#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	
	int n;
	cin>>n;
	int*arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	vector<int>output(n);
	output[0]=1;
	
	for(int i=1;i<n;i++)
	{output[i]=1;
		for(int j=i;j>=0;j--)
		{
			
			if(arr[j]<=arr[i])
			{
				output[i]=max(output[j]+1,output[i]);
			}
		}
	}
	
	int longest=output[0];
	
	for(int i=1;i<n;i++)
	{
		longest=max(longest,output[i]);
	}
	
	cout<<longest<<endl;
}
