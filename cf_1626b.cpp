#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define vll vector<long long>
#define vi vector<int>
#define vstr vector<string>
#define mll map<long long, long long>
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a > b) ? b : a)
#define pb push_back
#define sz(x) (int)(x).size()
#define fr first
#define sc second
#define prll pair<long long, long long>
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define rrep(i, a, n) for (ll i = n - 1; i >= a; i--)
#define search(arr, x) binarySearch(arr, 0, sz(arr) - 1, x)
typedef map<string, ll> msl;
#define mx 100001
#define mod 1000000007
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
ll extgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
ll revrsno(ll n)
{
    ll k = 0;
    vll z;
    while (n > 0)
    {
        z.pb(n % 10);
        n /= 10;
    }
    rep(i, 0, z.size()) k = k * 10 + z[i];
    return k;
}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
ll powm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll divide(ll a, ll b)
{
    return (a % mod) * powm(b, mod - 2) % mod;
}
ll mul(ll a, ll b)
{
    return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a, ll b)
{
    return (a % mod + b % mod) % mod;
}
ll Totfun(ll n)
{
    ll z = n;
    if (n % 2 == 0)
    {
        while (n % 2 == 0)
        {
            n /= 2;
        }
        z /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (isPrime(i) && n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            z -= z / i;
        }
    }
    if (n > 1)
    {
        z -= z / n;
    }
    return z;
}
ll maxPrimeFactor(ll n)
{
    ll maxPrime = -1;
    while (n % 2 == 0)
    {
        maxPrime = 2;
        n >>= 1;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            maxPrime = i;
            n = n / i;
        }
    }
    if (n > 2)
        maxPrime = n;
    return maxPrime;
}
ll fact[100001];
ll nCr(ll n, ll r)
{
    if (r > n || r < 0)
        return 0;
    ll z = fact[n];
    z = mul(z, powm(fact[n - r], mod - 2));
    z = mul(z, powm(fact[r], mod - 2));
    return z;
}

vector<string> strSplit(string s, string del = " ")
{
    int start = 0;
    int end = s.find(del);
    vector<string> result;
    while (end != -1)
    {
        result.pb(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    result.pb(s.substr(start, end - start));
    return result;
}

int binarySearch(vll arr, ll l, ll r, ll x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

/*
vll a[mx];
ll l[mx],d[mx];
void dfs(ll x,ll y){
   l[x]=1; d[x]=y;
   for(ll i:a[x])
   if(!l[i])
   dfs(i,y+1);
}
void bfs(ll x){
    queue<ll> q;
    q.push(x);
    l[x]=1;
    d[x]=0;
    while(!q.empty()){
        ll cur=q.front();
        q.pop();
        for(ll i : a[cur]){
            if(1-l[i]){
                q.push(i);
                d[i]=d[cur]+1;
                l[i]=1;
            }
        }
    }
}
*/
/*
 vector<int> primes;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
 */
// Function that returns true if num is

ll nextPrime(ll n)
{
    ll ans = n + 1;
    while (!isPrime(ans))
        ans++;
    return ans;
}

vll givePrime(int n)
{
    vll a(n);
    a[0] = 2;
    rep(i, 1, n)
    {
        a[i] = nextPrime(a[i - 1]);
    }
    return a;
}

vll primes = givePrime(100);

void solve()
{
    string s;
    ll max = 0, temp, flag = 0;
    cin >> s;
    rrep(i, 1, s.length())
    {
        if (s[i] + s[i - 1] - '0' - '0' >= max)
        {
            max = s[i] + s[i - 1] - '0' - '0';
            temp = i;
            if (max > 9)
            {
                i = -1;
                flag = 1;
            }
        }
    }
    if (flag)
    {
        rep(i, 0, s.length())
        {
            if (i == temp - 1)
            {
                cout << to_string(s[i] + s[i + 1] - '0' - '0');
                i++;
            }
            else
            {

                cout << s[i];
            }
        }
        cout << endl;
    }
    else
    {
        cout << to_string(s[0] + s[1] - '0' - '0');
        rep(i, 2, s.length())
        {
            cout << s[i];
        }
        cout << endl;
    }
    // Write your code here
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // with multiple test cases::::
    ll t;
    cin >> t;

    while (t--)
    {

        solve();
    }

    // without multiple test cases::::

    // solve();

    return 0;
}