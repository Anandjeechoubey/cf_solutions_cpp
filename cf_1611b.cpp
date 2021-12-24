#include <iostream>
using namespace std;

int main()
{
    int t,a,b;
    cin>>t;
    while (t--)
    {
        cin>>a>>b;
        if (a>b){
            int temp = a;
            a = b;
            b = temp;
        }
        if ( a==0 ){
            cout<<0<<endl;
            continue;
        }
        if ( b/a >= 3){
            cout<<a<<endl;
            continue;
        } else if ( a >= 2) {
            cout<<a/2<<endl;
            continue;
        }

        else {
            cout<<0<<endl;
        }
    }
    
    return 0;
}