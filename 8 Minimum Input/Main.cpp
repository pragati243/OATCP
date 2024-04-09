#include <bits/stdc++.h>
typedef long long ll;
/*const ll xz = 1e7 + 10;
ll fact[xz];
ll no[xz];
const ll mod = 1e7 + 10;*/
using namespace std;
 
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
 
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
 
int exp(int x, int n, int mod)
{
    int res = 1;
    x = x % mod;
    while (n > 0)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
 
    return res;
}
/*ll ff(ll x)
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < xz; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
}*/
 string fx(string s, int k)
{
    int n = s.size();
    stack<char> st;
    for (char x : s) {
        while (!st.empty() && k > 0
               && st.top() > x) {
            st.pop();
            k -= 1;
        }
 
        if (!st.empty() || x != '0')
            st.push(x);
    }

    while (!st.empty() && k--)
    {
        st.pop();
    }
    if (st.empty())
    {
        return "0";
    }

    while (!st.empty()) {
        s[n - 1] = st.top();
        st.pop();
        n -= 1;
    }
    return s.substr(n);
}
 
int main()
{ 
    // Open input and output files
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
   string s;
   cin>>s;
   int k;
   cin>>k;
   string ans = fx(s, k);
   cout<<ans<<endl;

       // Close files
    fclose(stdin);
    fclose(stdout);

}