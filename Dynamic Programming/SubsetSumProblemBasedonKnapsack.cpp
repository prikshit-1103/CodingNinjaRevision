//Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
//
//Input Format
//First line contains a single integer n (1<=n<=1000)
//Second line contains n space separated integers (1<=a[i]<=1000)
//Last line contains a single positive integer k (1<=k<=1000)


#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int* val,int n,int sum){

	bool** dp = new bool*[2];
	for(int i=0;i<=1;i++){
		dp[i] = new bool[sum+1];
	}

	for(int i=0;i<=sum;i++){
		dp[0][i] = false;
	}
	dp[0][0] = true;

	int flag = 1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){

			dp[flag][j] = dp[flag^1][j];

			if(j>=val[i-1]){
				dp[flag][j] = dp[flag][j] || dp[flag^1][j-val[i-1]];//using a 2d array with 2 rows in one run we are storing the result in 0th row and in next run 1st row.
				//for altering the row we are using ^ xor operator as 1^1=0 and 0^1=1;
			}
		}
		flag = flag ^ 1;
	}
	bool ans = dp[flag^1][sum];
	// delete dp array
	return ans;


}
int main(){


	int val[] = {1,3,5,7,9};
	int sum = 12;

	cout<<subsetSum(val,5,sum)<<endl;
	
	return 0;

}
