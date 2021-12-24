#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int t,ans;
   long long int k,x;
   cin>>t;
    while (t--) {
         cin>>k>>x;
         if ( x < k*(k+1)/2 ) {
             cout<<"0"<<endl;
         } else if ( x == k*(k+1)/2 ) {
             cout<<k<<endl;
         } else {
            cout<<k+1<<endl;
         }
    }
    return 0;
}