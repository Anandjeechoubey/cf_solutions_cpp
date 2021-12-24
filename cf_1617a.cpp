#include <iostream>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while (t--)
   {
       string s,t;
       int flag=0;
       cin>>s>>t;
       for (int i = 0; i < s.length()-1; i++)
       {
           for (int j = 0; j < s.length()-1-i; j++)
           {
               if(s[j] == 'a')
               {
                   flag=1;
               }
               if (s[j] > s[j+1])
               {
                    char temp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = temp;
               }
           }
           if ( t == "abc" && s[s.length()-1-i] == 'b' && s[s.length() - i] == 'c'  && flag)
           {
                s[s.length()-1-i] = 'c';
                s[s.length()-i] = 'b';
           }
           
       }

       cout<<s<<endl;
       
   }
   
    return 0;
}