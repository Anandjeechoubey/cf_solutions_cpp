#include <iostream>
using namespace std;

int main()
{
    int t, result=0;
    cin>>t;

    while (t--)
    {
        int count=0, temp;
        for (int i = 0; i < 3; i++)
        {
            cin>>temp;
            count += temp;
        }
        if (count >= 2)
        {
            result++;
        }
        
    }
    cout<<result;
    return 0;
}