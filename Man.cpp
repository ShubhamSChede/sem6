#include<iostream>
using namespace std;
//as per GE Thomas .. not ieee
void manchestar(string s)
{
    cout << "Manchester Encoding: ";
   for(char c : s)
   {
    if(c=='0')
    {
        cout<<" 10 ";
    }
    else if(c=='1')
    {
        cout<<" 01 ";
    }
   }
   cout << endl;
}

void diffmanchestar(string s, int prev)
{
    cout<< "Differential Manchester Encoding: ";
        for(char c : s)
        {
            if(c=='0')
            {
                if(prev == 0)
                {
                    prev = 1; 
                    cout<<prev<<!prev ;
                    prev = !prev; 
                }
                else if (prev == 1)
                {
                    prev = 0; 
                    cout<<prev<<!prev ;
                    prev = !prev; 
                }
            }
            else if(c=='1')
            {
                cout<<prev<<!prev ;
                prev = !prev; 
            }
        }
}

int main()
{
    string s; int prev;
    cout << "Enter a string: ";
    cin >> s;
    cout<< "enter prev";
    cin>>prev;
    manchestar(s);
    diffmanchestar(s,prev);

    return 0;
}