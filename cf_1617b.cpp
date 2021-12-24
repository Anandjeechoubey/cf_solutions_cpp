#include <iostream>
using namespace std;

int main()
{
   int t,n;
   cin>>t;
   while (t--)
   {
       cin>>n;
       for (int i = n/2; i > 0; i--)
       {
           if   (n%i == 0)
           {
               cout<<i<<endl;
               break;
           }
       }
       
   }
    return 0;
}