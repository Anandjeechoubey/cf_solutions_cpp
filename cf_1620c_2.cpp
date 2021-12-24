#include <iostream>
#include <vector>
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
    int t, n, k, countAst, countA, val, flag;
    string s, res;
    long long int x;
    vector<int> v;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> x >> s;
        countAst = 0;
        flag = 0;
        countA = 0;
        val = 1;
        res = "";
        reverseStr(s);
        for (int i = 0; i < s.length(); i++)
        {
            if (flag)
            {
                if (s[i] == 'a')
                {
                    countA++;
                }
                continue;
            }
            if (s[i] == '*')
            {
                countAst++;
                continue;
            }
            if (s[i] == 'a')
            {
                val *= (countAst * k + 1);
                if (val > x)
                {
                    flag = 1;
                }
                v.push_back(countAst);
                countA++;
                countAst = 0;
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (k * v[i] + 1 <= x)
            {
                for (int j = 0; j < x - 1; j++)
                    res += 'b';
                for (int j = 0; j < countA; j++)
                    res += 'a';
                break;
            }
        }
        reverseStr(res);
        cout << res << endl;
    }
    return 0;
}