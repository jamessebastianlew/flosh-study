#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;
const int mxE = 1e5+5;

int V, E, a, b, x;
vector<int> adj[mxV];
vector<int> topsort;

bool vis[mxV];
void dfs(int curr) {
    vis[curr] = true;
    for(int v : adj[curr])
        if(!vis[v]) dfs(v);
    topsort.push_back(curr);
}

int main() {

    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b);

    for(int i=1; i<=V; ++i)
        if(!vis[i]) dfs(i);

    for(int i=0; i<(V>>1); ++i)
        swap(topsort[i], topsort[V-i-1]);

    for(int i=0; i<V; ++i)
        cout << topsort[i] << ' ';
    cout << endl;


    return 0;
}
