#include <iostream>
using namespace std;

int main()
{
    long long int t, w, h, n, a, b, max, trash;
    cin >> t;
    while (t--)
    {
        cin >> w >> h;
        max = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                {
                    cin >> a;
                }
                else if (j == n - 1)
                {
                    cin >> b;
                }
                else
                {
                    cin >> trash;
                }
            }
            if (i < 2)
            {
                if (h * (b - a) > max)
                    max = h * (b - a);
            }
            else
            {
                if (w * (b - a) > max)
                    max = w * (b - a);
            }
        }
        cout << max << endl;
    }
    return 0;
}