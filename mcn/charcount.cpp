#include<iostream>
#include<string.h>
using namespace std;


void transmit()
{
   cout<<"enter string :";
   string s; int size; int len;
   cin>>s; 
   cout<<endl;  
   cout << "enter size :";
   cin>>size;
   cout<<endl;
   len=s.length();
   for(int i=0;i<len;i+=size)
   {
    int count= min(size,len-i);
    cout<<count+1;
    cout<<s.substr(i,count);
   }
}

void receive()
{
   cout<<"enter string :";
   string s,original;
   int len;
   cin>>s; 
   len=s.length();
   for(int i=0; i<len;)
   {
    int count=s[i++]-'0';
    original += s.substr(i,count-1);
    i=i+count-1;
   }
   cout<<endl<<"output :"<<original;
}

int main()
{
    int c;
    while(true)
    {
        cout <<endl<<"enter choice: 1 for transmit , 2 to recive, 3 to exit: ";
        cin >> c;
        cout<<endl;
        switch(c)
        {
            case 1: transmit(); break;
            case 2: receive(); break;
            case 3: cout << "Exiting..." << endl; exit(0); break;
            default: cout << "Invalid choice. Please try again." << endl; break;
        }
    }
    
    return 0;
}