#include <iostream>
using namespace std;

void reverseStr(string &str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

int main()
{
    int t, n, k, countAst, flag;
    string s, res;
    long long int x;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> x >> s;
        x--;
        reverseStr(s);
        countAst = 0;
        flag = 0;
        res = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (flag)
            {
                if (s[i] == 'a')
                    res += 'a';
                else
                    continue;
            }
            if (s[i] == '*')
            {
                countAst++;
                continue;
            }

            if (x > (k + 1) * countAst)
            {
                x -= (k + 1) * countAst;

                res += 'a';
                countAst = 0;
            }
            else
            {
                for (int j = 0; j < x; j++)
                    res += 'b';
                res += 'a';
                flag = 1;
            }
        }
        reverseStr(res);
        cout << res << endl;
    }
    return 0;
}