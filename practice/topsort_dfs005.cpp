#include <bits/stdc++.h>

using namespace std;

int V, E, a,b,x;
const int mxV = 1e5+5;
const int mxE = 1e5+5;

vector<int> adj[mxV];
vector<int> topsort;

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

    for(int i=topsort.size()-1; i>=0; --i)
        cout << topsort[i] << ' ';
    cout << endl;

    return 0;
}
