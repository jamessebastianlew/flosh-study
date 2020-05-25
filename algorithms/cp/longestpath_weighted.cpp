#include <bits/stdc++.h>

using namespace std;

void amax(int& a, int b) {
    a = a>b?a:b;
}

int V, E, a, b, x;
const int mxV = 1e5+5;
const int mxE = 1e5+5;

vector<array<int,2>> adj[mxV]; // v, val

bool vis[mxV];
int dp[mxV];
int dfs(int u) {
    if(vis[u])
        return dp[u];
    vis[u] = true;
    for(array<int, 2> v : adj[u])
        amax(dp[u], dfs(v[0])+v[1]);
    return dp[u];
}

int main() {

    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b >> x, adj[a].push_back({b, x});

    for(int i=1; i<=V; ++i)
        if(!vis[i]) dfs(i);
    int ans = 0;
    for(int i=1; i<=V; ++i)
        amax(ans, dp[i]);

    cout << ans << endl;

    return 0;
}
