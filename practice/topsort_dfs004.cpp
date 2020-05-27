#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;

int V, E, a, b, x;
vector<int> adj[mxV];
int len = 0;
int topsort[mxV];

bool vis[mxV];
void dfs(int u) {
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfs(v);
    topsort[len++] = u;
}

int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b);

    for(int i=1; i<=V; ++i) 
        if(!vis[i]) dfs(i);

    for(int i=len-1; i>-1; --i)
        cout << topsort[i] << ' ';
    cout << endl;

    return 0;
}
