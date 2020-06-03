#include <bits/stdc++.h>

using namespace std;

int V, E, a,b,x;
const int mxV = 1e5+5;
const int mxE = 1e5+5;

vector<int> adj[mxV], adj_t[mxV], newadj[mxV], topsort;

bool vis[mxV];
int leader[mxV];

void dfsone(int u) {
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfsone(v);
    topsort.push_back(u);
}

void dfstwo(int u, int lead) {
    leader[u] = lead; vis[u] = true;
    for(int v : adj_t[u])
        if(!vis[v]) dfstwo(v, lead);
}

int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b), adj_t[b].push_back(a);

    for(int i=1; i<=V; ++i)
        if(!vis[i]) dfsone(i);

    memset(vis, 0, sizeof(vis));
    int lead = 0;
    for(int i=V-1; i>=0; --i)
        if(!vis[topsort[i]]) dfstwo(topsort[i], ++lead);

    set<array<int, 2>> snes;
    for(int i=1; i<=V; ++i) for(int v : adj[i])
        if(leader[i]!=leader[v] && !snes.count({leader[i], leader[v]}))
            newadj[leader[i]].push_back(leader[v]), snes.insert({leader[i], leader[v]});

    for(int i=1; i<=lead; ++i) for(int v : newadj[i])
        cout << i << ' ' << v << endl;

    return 0;
}
