#include<iostream>
using namespace std;
void bitstuff()
{
    string s;
    cout<<"enter string"<<endl;
    cin>>s;
    string op="flag";
    int count=0;
    int len = s.length();
    for(int i=0;i< len ; i++)
    {
        op= op+s[i];
        if(s[i]=='1')
        count++;
        if(s[i]=='0')
        count=0;
        if(count==5)
        {
            op=op+'0';
        }
    }
    op=op+"flag";
    cout<<"output : "<<op;

}

void destuff()
{
    string s;
    cout<<"enter string"<<endl;
    cin>>s;
    int count=0;
     string output;
    string st= s.substr(0,4);
    string en= s.substr(s.length()-4, 4);
    if( st == "flag" && en =="flag")
    {
        for( int i=4 ;i< s.length()-4 ;i++)
        {
           
            output += s[i];
            if(s[i]=='1')
            count++;
            if(s[i]=='0')
            count=0;
            if(count==5)
            {
                i++;
            }
        }
    }
    cout<<output;
}


int main()
{
    destuff();
}