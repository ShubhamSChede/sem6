#include<iostream>
#include<string>
using namespace std;

void stuff()
{
 int n;
 cout<<"enter number of words :";
 cin>>n;
 cout<<endl;
 string word,output="flag ";
 for(int i=0;i<n;i++)
 {
    cin>>word;
    if( word == "flag" || word == "esc")
    {
       output+=" esc ";
       output+=word;
    }
    else
     output+=word;
 }   
output+=" flag";
cout<<endl<<output<<endl;
}

void destuff()
{
    
}

int main()
{
    stuff();
    destuff();
}