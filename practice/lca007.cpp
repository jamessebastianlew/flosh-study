#include <bits/stdc++.h>

using namespace std;

const int mxv = 1e5+5;
const int mxk = 21;
int V,E,a,b,x;

vector<int> adj[mxv];

int jp[mxv][mxk];
int in[mxv]; int out[mxv];

int cnt;

void dfs(int u, int par) {
    in[u] = ++cnt; jp[u][0] = par;
    for(int v : adj[u]) if(v!=par) dfs(v,u);
    out[u] = ++cnt;
}

void build() {
    for(int k=1; k<mxk; ++k)
        for(int i=1; i<=V; ++i)
            jp[i][k] = jp[jp[i][k-1]][k-1];
}

bool isanc(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
    if(isanc(u,v) || isanc(v,u)) return isanc(u,v)?u:v;
    for(int i=mxk-1; i>=0; --i)
        if(!isanc(jp[u][i], v)) u = jp[u][i];
    return jp[u][0];
}

int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
    dfs(1,1); build();

    int q;
    cin >> q;
    while(q--)
        cin >> a >> b, cout << lca(a,b) << endl;
    
    return 0;
}

