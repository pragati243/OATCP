#include <bits/stdc++.h>
#define ll long long
#define maxN 1000
using namespace std;
int N;
char c[maxN + 1][maxN + 1];
ll dp[maxN + 1][maxN + 1];

void solveCase(const string& inputFile, ofstream& outFile) {
    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        cerr << "Error opening input file: " << inputFile << endl;
        return;
    }
    inFile >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            inFile >> c[i][j];
    // Base case: only one way to reach the start square if it's not a trap
    dp[1][1] = (c[1][1] == '.');
    // Fill the first row
    for (int j = 2; j <= N; j++) {
        dp[1][j] = (c[1][j] == '.' && dp[1][j - 1]);
    }
    // Fill the first column
    for (int i = 2; i <= N; i++) {
        dp[i][1] = (c[i][1] == '.' && dp[i - 1][1]);
    }
    // Fill the remaining cells
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            if (c[i][j] == '.') {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    outFile << "Case 1: " << dp[N][N] << endl;
}

int main() {
    ofstream outFile("output.txt");
    if (!outFile.is_open()) {
        cerr << "Error opening output file" << endl;
        return 1;
    }
    solveCase("input1.txt", outFile);
    solveCase("input2.txt", outFile);
    outFile.close();
    return 0;
}