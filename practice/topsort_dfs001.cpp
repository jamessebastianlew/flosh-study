#include <bits/stdc++.h>

using namespace std;

int V, E;

const int mxV = 1e5+5;
const int mxE = 1e5+5;
vector<int> adj[mxV];
vector<int> topsort;

bool vis[mxV];
void dfs(int node) {
    vis[node] = true;
    for(int v : adj[node])
        if(!vis[v]) dfs(v);
    topsort.push_back(node);
}

int main() {

    cin >> V >> E;

    int a, b;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b);

    for(int i=1; i<=V; ++i) if(!vis[i]) dfs(i);

    int n=topsort.size();
    for(int i=0; i<(n>>1); ++i)
        swap(topsort[i], topsort[n-i-1]);

    for(int i=0; i<n; ++i)
        cout << topsort[i] << ' ';
    cout << endl;

    return 0;
}
