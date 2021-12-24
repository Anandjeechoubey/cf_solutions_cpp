#include <iostream>
using namespace std;

int main()
{
    int y, w, d;
    cin>>y>>w;
    if(y > w){
        d=7 - y;
    } else {
        d=7 - w;
    }

    switch (d)
    {
    case 1:
        cout<<"1/6";
        break;
    case 2:
        cout<<"1/3";
        break;
    case 3:
        cout<<"1/2";
        break;
    case 4:
        cout<<"2/3";
        break;
    case 5:
        cout<<"5/6";
        break;
    case 6:
        cout<<"1/1";
        break;
    default:
        cout<<"0/1";
        break;
    }
    return 0;
}