//Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - 
//correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion.
//Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory.
//Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. 
//He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only).
//So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary.
//" As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
//INPUT CONSTRAINTS
//1=N=30000
//sum(len(string[i]))=2*10^5
//1=Q=10^3
//INPUT FORMAT
//Single integer N which denotes the size of words which are input as dictionary
//N lines of input, where each line is a string of consisting lowercase letter
//Single integer Q which denotes the number of queries.
//Q number of lines describing the query string on each line given by user
//OUTPUT FORMAT
//If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes
//
//NOTE: All strings are lowercase
//SAMPLE INPUT
//3
//fact
//factorial
//factory
//2
//fact
//pradyumn

/*#include <bits/stdc++.h>
using namespace std;

struct trienode
{  
  bool isleaf=false;  
  trienode*arr[26];
};

trienode*newnode()
{
  trienode*temp=new trienode;
  
  for(int i=0;i<26;i++)
      temp->arr[i]=NULL;
    
   return temp;
}

void inserttrie(trienode*head,string s)
{ trienode*curr=head;
  for(int i=0;i<s.length();i++)
  {
      int value=s[i]-'a';
      if(curr->arr[value]==NULL)
      { 
          curr->arr[value]=newnode();
      }
      curr=curr->arr[value];
  }
   curr->isleaf=true;
 

}

void dfs(trienode*head,string s,vector<string>&result)
{   
    
    trienode*curr=head;
    if(curr==NULL)
        return;
    
    if(curr->isleaf)
            {
                result.push_back(s);
                
            }
    
    for(int i=0;i<26;i++)
    {
        if(curr->arr[i]!=NULL)
        {
            char ch='a'+i;
            string s1(1,ch);
        
            curr=curr->arr[i];
            dfs(curr,s+s1,result);
        }
       
        
    }
    
    
}


vector<string> query(trienode*head,string s)
{
    vector<string>result;
    trienode*curr=head;
    for(int i=0;i<s.length();i++)
    {   
        int value=s[i]-'a';
        if(curr->arr[value]==NULL)
            return result;
        
        curr=curr->arr[value];
    }
    string s2="";
    if(curr!=NULL)
    {
    dfs(curr,s2,result);
    }
    return result;
    
}

int main()
{
    int n;
    cin>>n;
    
    trienode*head=newnode();
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        inserttrie(head,s);
        
    }
    
    int q;
    cin>>q;
    vector<string>recommendations;
    for(int i=0;i<q;i++)
    {
        string s;
        cin>>s;
        recommendations=query(head,s);
       if(!recommendations.empty())  
        for(auto itr=recommendations.begin();itr!=recommendations.end();itr++)
        {   
            string output=s+*itr;
            cout<<output<<endl;
        }
      else
      {
          inserttrie(head,s);
          cout<<"No suggestions"<<endl;
      }
    }
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;

struct trienode
{  
  bool isleaf=false;  
  trienode*arr[26];
};

trienode*newnode()
{
  trienode*temp=new trienode;
  
  for(int i=0;i<26;i++)
      temp->arr[i]=NULL;
   return temp;
}

void inserttrie(trienode*head,string s)
{
    trienode*curr=head;
    for(int i=0;i<s.length();i++)
    {
        int value=s[i]-'a';
        if(curr->arr[value]==NULL)
        { 
            curr->arr[value]=newnode();
        }
        curr=curr->arr[value];
    }
    curr->isleaf=true;
 

}

void dfs(trienode* head,string s)
{
    //cout<<"Working\n";
    if(!head)
        return;
    if(head->isleaf)
        cout<<s<<endl;
    for(int i=0;i<26;i++)
    {
        if(head->arr[i])
        {
            char ch = 'a';
            ch+=i;
            dfs(head->arr[i],s+ch);
        }
    }
}


// void query(trienode*head,string s)
// {
//     if(!head)
//         return;
// //     vector<string>result;
// //     trienode*curr=head;
// //     for(int i=0;i<s.length();i++)
// //     {   
// //         int value=s[i]-'a';
// //         if(curr->arr[value]==NULL)
// //             return result;
        
// //         curr=curr->arr[value];
// //     }
// //     string s2="";
// //     dfs(curr,s2,result);
// //     return result;
    
// }

int main()
{
    int n;
    cin>>n;
    
    trienode*head=newnode();
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        inserttrie(head,s);
        
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string s;
        cin>>s;
        trienode* curr = head;
        bool flag = true;
        for(int i=0;i<s.length();i++)
        {
            int index = s[i] - 'a';
            if(curr->arr[index])
            {
                curr = curr->arr[index];
            }
            else
            {
                cout<<"No suggestions\n";
                flag = false;
                break;
            }
        }
        if(curr && flag)
        {
            dfs(curr,s);
        }
        if(!flag)
            inserttrie(head,s);   
    }
    return 0;
}
