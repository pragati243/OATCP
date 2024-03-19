#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6;
const int MOD = 1e9 + 7;
int N, dp[maxN + 1];

int solve(int n){
    if (n == 0)
    {
        return 1;
    }
    for (int i = 0; i <= n; ++i)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6 && i - j >= 0; j++)
        {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    return dp[n];
}
int main(){
    ifstream inFile("input.txt");
    if (!inFile.is_open())
    {
        cerr << "Error opening input file" << endl;
        return 1;
    }
    ofstream outFile("output.txt");
    if (!outFile.is_open())
    {
        cerr << "Error opening output file" << endl;
        return 1;
    }
    int T;
    inFile >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n;
        inFile >> n;
        if (n < 0)
        {
            outFile << "Case #" << t << ": Invalid input (negative sum)" << endl;
            continue;
        }
        int ways = solve(n);
        outFile << "Case #" << t << ": " << ways << endl;
    }
    inFile.close();
    outFile.close();

    return 0;
}