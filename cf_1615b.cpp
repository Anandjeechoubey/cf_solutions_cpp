#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define vll vector<long long>
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define loop(i, a, n) for (ll i = a; i < n; i++)
#define mx 200001

ll history[mx][19];
void findDp()
{
    loop(i, 0, 19)
    {

        loop(j, 1, mx)
        {
            if ((j & (1 << i)))
                history[j][i] = 1;
            else
                history[j][i] = 0;
        }
    }

    loop(i, 0, 19)
    {
        loop(j, 1, mx)
        {
            history[j][i] += history[j - 1][i];
        }
    }
}

void solution()
{

    ll l, r;
    ll ans = 1e9;
    cin >> l >> r;

    loop(i, 0, 19)
    {
        ans = min(ans, (r - l + 1) - (history[r][i] - (history[l - 1][i])));
    }

    cout << ans << endl;
    // Write your code here
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // with multiple test cases::::
    findDp();
    ll t;
    cin >> t;

    while (t--)
    {

        solution();
        cout << endl;
    }

    // without multiple test cases::::

    // solution();

    return 0;
}