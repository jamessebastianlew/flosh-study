#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;
int V, E, a,b,x;

vector<int> adj[mxV], adj_t[mxV], newadj[mxV], topsort;

bool vis[mxV];
void dfsone(int u) {
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfsone(v);
    topsort.push_back(u);
}

int leader[mxV];
void dfstwo(int u, int lead) {
    vis[u] = true, leader[u] = lead;
    for(int v : adj_t[u])
        if(!vis[v]) dfstwo(v, lead);
}

int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b), adj_t[b].push_back(a);

    for(int i=1; i<=V; ++i) if(!vis[i]) dfsone(i);

    int lead = 0;
    memset(vis,0,sizeof(vis));
    for(int i=V-1; i>=0; --i) if(!vis[topsort[i]]) dfstwo(topsort[i], ++lead);

    for(int i=1; i<=V; ++i) for(int v : adj[i])
        if(leader[i]!=leader[v]) newadj[leader[i]].push_back(leader[v]);

    for(int i=1; i<=lead; ++i) for(int v : newadj[i])
        cout << i << ' ' << v << endl;

    return 0;
}
