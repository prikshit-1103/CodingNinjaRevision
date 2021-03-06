/*In Little Flowers Public School, there are many students with same first names. 
You are given a task to find the students with same names. 
You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. 
If all the names are unique, print -1 instead.*/


#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;
void countdiffnames(string s){
	string name = "";
	unordered_map<string,int> freq;
	for(int i =0; i < s.length(); i++){
		if(s[i] == ' ' ){
			freq[name]++;
			name = "";
		}
		else{
			name = name + s[i];
		}
	}
	freq[name]++;
	int count = 0;
	unordered_map<string,int>::iterator it;
	for(it = freq.begin(); it!= freq.end(); it++){
		if(it->second >= 2){
			count++;
		}
	}
	if(count == 0){
		cout <<"-1"<< endl;
		return;
	}
	for(it = freq.begin(); it!= freq.end(); it++){
		if(it->second >=2){
			cout << it->first <<" " << it->second << endl;
		}
	}
}


int main(){
	string s;
	getline(cin, s);
	countdiffnames(s);
}
