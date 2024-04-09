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
int fx(vector<int>& nums, int n) {
        int xx=nums.size();
        long long mx=0,ans=0;
        for(int i=0;i<xx;i++){
            while(nums[i]>(mx+1)){
                mx=2*mx+1;
                ans++;
                if(mx>=n){
                    return ans;
                }
            }
            mx+=nums[i];
            if(mx>=n){
                return ans;
            }
        }
        while(mx<n){
            mx=2*mx+1;
            ans++;
        }
        return ans;
    }
int main()
{ 
    // Open input and output files
    freopen("sample_input1.txt", "r", stdin);
    freopen("sample_output1.txt", "w", stdout);
    
    vector<int>v;
    int x;
    while(cin>>x)
    {
        v.push_back(x);
        if (cin.peek() == '\n') // Check if the next character is a newline
        {
            break; // Exit the loop if newline detected
        }
    }
 
    int n;
    cin>>n;
    int ans=fx(v,n);
       // Close files
    cout<<ans;

    fclose(stdin);
    fclose(stdout);

}