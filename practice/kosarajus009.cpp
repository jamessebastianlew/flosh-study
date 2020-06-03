#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;
const int mxE = 1e5+5;

vector<int> adj[mxV];
vector<int> adj_t[mxV];
vector<int> topsort;
vector<int> newadj;

set<array<int, 2>> fromto;

bool vis[mxV];
void dfsone(int u) {
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfsone(v);
    topsort.push_back(u);
}

int leader[mxV];
void dfstwo(int u, int lead) {
    vis[u] = true; leader[u] = lead;
    for(int v : adj_t[mxV])
        if(!vis[v]) dfstwo(v);
}

int main() {

    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b);
    
    for(int i=1; i<=V; ++i)
        if(!vis[i]) dfsone(i);

    for(int i=1; i<=V; ++i)
        for(int v : adj[i])
            if(leader[i] != leader[v])
                if(!fromto.count({leader[i], leader[v]}))
                    newadj[leader[i]].push_back(leader[v]), fromto.insert({leader[i], leader[v]});

    return 0;
}
