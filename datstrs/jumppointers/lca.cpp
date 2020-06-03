#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;
const int mxE = 1e5+5;
const int mxK = 17;

int V, E, a, b, x;
int K;

vector<int> adj[mxV];
int in[mxV], out[mxV];
int jp[mxV][mxK];

int cnt = 0;
void dfs(int u, int par) {
    in[u] = ++cnt; jp[u][0] = par;
    for(int v : adj[u])
        if(v != par) dfs(v, u);
    out[u] = ++cnt;
}

void build() {
    for(int k=1; k<mxK; ++k)
        for(int i=1; i<=V; ++i)
            jp[i][k] = jp[jp[i][k-1]][k-1];
}

// u is an ancestor of v
bool isanc(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
    if(isanc(u, v) || isanc(v, u)) return isanc(u, v)?u:v;
    for(int i=16; i>=0; --i)
        if(!isanc(jp[a][i], b)) a=jp[a][i];
    return jp[a][0];
}

int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

    dfs(1, 1); build();

    int q;
    cin >> q;
    while(q--) {
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }

    return 0;
}
