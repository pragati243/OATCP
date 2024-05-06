/*
Problem Name: Valid Arrangement Of Pairs
Author: Vineet Motwani
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define vll vector<int>

int findStartNode(unordered_map<int, int>& degree) {
    int start = -1;
    for(auto& [i, cnt] : degree) {
        if(cnt == 1) 
            return i;
        start = i;
    }
    return 0;  // Dummy return statement, will never be executed
}

void findEulerianPath(unordered_map<int, vector<int>>& graph, vector<vector<int>>& path, int node) {    
    auto& adj = graph[node];
    while(adj.size()) {
        int adjnode = adj.back();
        adj.pop_back();
        findEulerianPath(graph, path, adjnode);
        path.push_back({node, adjnode});
    }
}

signed main() {
    int n;
    cin>>n;
    vector<pair<int,int>> pairs;
    int a,b;
    for(int i=0; i<n; i++) {
        cin>>a>>b;
        pairs.push_back({a,b});
    }

    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> degree; 
    
    for(auto& pair : pairs) {
        int u = pair.first, v = pair.second;
        graph[u].push_back(v);
        degree[u]++;
        degree[v]--;
    }
    
    int start = findStartNode(degree);

    vector<vector<int>> path;
    findEulerianPath(graph, path, start);
    reverse(path.begin(), path.end());

    if(path.size() != n) {
        cout<<"No Valid Arrangement Possible\n";
        return 0;
    }

    cout<<"Path : ";
    cout<<path[0][0];
    for(int i=0; i<n; i++)
        cout<<"->"<<path[i][1];
    cout<<endl;

    cout<<"Arranged Pairs : [ ";
    for(int i=0; i<n-1; i++) {
        cout<<"("<<path[i][0]<<","<<path[i][1]<<"), ";
    }
    cout<<"("<<path[n-1][0]<<","<<path[n-1][1]<<")";
    cout<<" ]";

    return 0;
}