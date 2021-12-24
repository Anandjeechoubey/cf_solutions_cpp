#include <iostream>
using namespace std;

int main()
{
    int t, countN;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        countN = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'N')
            {
                countN++;
            }
        }
        if (countN == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}