#include<bits/stdc++.h>
#include<vector>
#include<map>
#include<iterator>
using namespace std;


int FindSpace(string pi,map<string,string>numbersMap,map<int,int>&MapRes,int index)
{
	if(pi.length()==0)
		return -1;
	if(MapRes.find(index)!=MapRes.end())
	{
		return MapRes[index];
	}
	
	int minspace=INT_MAX;
	for(int i=1;i<=pi.length();i++)
	{
		string pref=pi.substr(0,i);
		
	  if(numbersMap.find(pref)!=numbersMap.end())
		{ int remlength=pi.length()-i;
		  string rem=pi.substr(i,remlength);
	      int space=FindSpace(rem,numbersMap,MapRes,i+1);
	      if(minspace==INT_MAX)
		  minspace=min(minspace,space);
		  else
		  minspace=min(minspace,space+1);
		}
	 }
	MapRes[index]=minspace;
	return MapRes[index];
}

int numbersInPi(string pi, vector<string> numbers) {
 map<string,string>numbersMap;
 map<int,int>strRes;
	for(int i=0;i<numbers.size();i++)
	{
		numbersMap[numbers[i]]=numbers[i];
	}
	
	int minspace=FindSpace(pi,numbersMap,strRes,0);
	
	return minspace;
}

    

int main()
{
 string pi="3141592653589793238462643383279";
 string arr[]={"3",
    "1",
    "4",
    "592",
    "65",
    "55",
    "35",
    "8",
    "9793",
    "2384626",
    "383279"};
    vector<string>numbers;
 for(int i=0;i<11;i++)
 {
 	numbers.push_back(arr[i]);
 }
 int res=numbersInPi( pi, numbers);
 cout<<res<<endl;
}
