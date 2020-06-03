#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;

vector<int> adj[mxV];
vector<int> topsort;
int V, E,a,b,x;

bool vis[mxV];
void dfs(int u) {
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfs(v);
    topsort.push_back(u);
}

int main() {

    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b);

    for(int i=1; i<=V; ++i)
        if(!vis[i]) dfs(i);

    const int n = topsort.size();
    for(int i=0; i<(n>>1); ++i)
        swap(topsort[i], topsort[n-i-1]);
    for(int i : topsort)
        cout << i << endl;

    return 0;
}
