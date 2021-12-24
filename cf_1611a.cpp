#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int num;
        cin>>num;
        if (num %2 == 0)
        {
            cout<<0<<endl;
            continue;
        }
        int flag=0;
        while (num/10)
        {
            if (num%2 == 0)
            {
                flag=1;
            }
            num /= 10;
        }
        
        if (num%2 == 0)
        {
            cout<<1<<endl;
            continue;
        } 

        if (flag)
        {
            cout<<2<<endl;
            continue;
        }
        cout<<-1<<endl;
    }
    
    return 0;
}