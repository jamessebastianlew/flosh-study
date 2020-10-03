#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+5;
vector<int> topsort;
vector<int> adj[mxn];
int V, E, a,b,x;

bool vis[mxn];

void dfs(int u) {
    vis[u] = true;
    for(int v : adj[u])  if(!vis[v]) dfs(v);
    topsort.push_back(u);
}

int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i) cin >> a >> b, adj[a].push_back(b);
    for(int i=1; i<=V; ++i) if(!vis[i]) dfs(i);
    for(int i=0; i<(V>>1); ++i) swap(topsort[i], topsort[V-i-1]);
    for(int i=0; i<V; ++i) cout << topsort[i] << ' '; cout << endl;
    return 0;
}
