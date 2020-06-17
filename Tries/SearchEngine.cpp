//Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, 
//the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
//Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight 
//and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database,
//that completes the given incomplete search string. In case no such string exists, print -1.
//INPUT
//First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.
//
//Next q lines follow, each line having a string t, which needs to be completed.
//OUTPUT
//Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.


#include <bits/stdc++.h>
using namespace std;

struct trienode
{
    int weight;
    trienode*arr[26];
};

trienode*newnode()
{
    trienode*temp=new trienode;
    temp->weight=0;
    for(int i=0;i<26;i++)
        temp->arr[i]=NULL;
    return temp;
}

void insert(trienode*head, string s,int weigh)
{
    trienode*curr=head;
    
    for(int i=0;i<s.length();i++)
    { int value=s[i]-'a';
      
        if(curr->arr[value]==NULL)
        {
           curr->arr[value]=newnode() ;
        }
     curr->weight=max(curr->weight,weigh); 
     curr=curr->arr[value];
       
        
    }
    //curr->weight=max(curr->weight,weigh);
}

int query(trienode*head,string s)
{
    trienode*curr=head;
    for(int i=0;i<s.length();i++)
    {
       int value=s[i]-'a';
       if(curr->arr[value]==NULL)
           return -1;
        else
         curr=curr->arr[value];
    }
    return curr->weight;
}


int main()
{int n,q;
 cin>>n>>q;
 
 trienode*head=new trienode;
 head->weight=0;
 for(int i=0;i<26;i++)
 {
     head->arr[i]=NULL;
 }
 
 for(int i=0;i<n;i++)
 {
     string s;
     int weight;
     cin>>s>>weight;
     
     insert(head,s,weight);
 }
 
 for(int i=0;i<q;i++)
 {
     string t;
     int res;
     cin>>t;
     res=query(head,t);
     cout<<res<<endl;
 }
    return 0;
}

