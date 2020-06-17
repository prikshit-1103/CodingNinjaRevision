/*In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design & Analysis and Operating Systems. 
Marks for each subject of all the students are provided to you.
You have to tell the position of each student in the class. Print the names of each student according to their position in class. 
 Tie is broken on the basis of their roll numbers. 
Between two students having same marks, the one with less roll number will have higher rank. The input is provided in order of roll number.*/



#include<bits/stdc++.h>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;


bool compare( pair<string,int>p1, pair<string,int>p2)
{
    return p1.second > p2.second ;
}

int main()
{int n;
 cin>>n;
vector<pair<string,int>>arr;
 for(int i=0;i<n;i++)
 {string name;
  int m1,m2,m3;
  cin>>name;
  cin>>m1>>m2>>m3;
  int sum =m1+m2+m3;
  arr.push_back(make_pair(name,sum));
  }
 
 stable_sort(arr.begin(),arr.end(),compare);
int pos=1;

  for(auto itr=arr.begin();itr!=arr.end();itr++)
   {
       cout<<pos++<<" "<< itr->first << endl;
   }
	return 0;
}

