#include <bits/stdc++.h>

using namespace std;

void amax(int& a, int b) { a=a>b?a:b; }

const int mxV = 1e5+5;
const int mxE = 1e5+5;
const int INF = 0x3f3f3f3f;
const int nINF = 0xc0c0c0c0;

int V, E, a, b, x;
vector<int> adj[mxV];

bool vis[mxV];
int dp[mxV];
int dfs(int u) {
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) amax(dp[u], dfs(v)+1);
        else amax(dp[u], dp[v]+1);
    return dp[u];
}

int main() {
    
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b);

    for(int i=1; i<=V; ++i)
        if(!vis[i]) dfs(i);
    int ans = 0;
    for(int i=1; i<=V; ++i)
        amax(ans, dp[i]);

    cout << ans << endl;
    
    return 0;
}
