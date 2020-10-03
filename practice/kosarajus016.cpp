#include <bits/stdc++.h>
using namespace std;

int V, E, a,b,x;
const int mxe = 1e5+5;
const int mxv = 1e5+5;
vector<int> topsort, adj[mxv], adj_t[mxv], newadj[mxv];

bool vis[mxv];
void dfsone(int u) {
    vis[u] = true;
    for(int v : adj[u]) if(!vis[v]) dfsone(v);
    topsort.push_back(u);
}

int leader[mxv];
void dfstwo(int u, int lead) {
    leader[u] = lead; vis[u] = true;
    for(int v : adj_t[u]) if(!vis[v]) dfstwo(v, lead);
}

int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b), adj_t[b].push_back(a);

    for(int i=1; i<=V; ++i) if(!vis[i]) dfsone(i);

    int lead = 0;
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=V; ++i) if(!vis[i]) dfstwo(i, ++lead);

    set<array<int,2>> st;
    for(int i=1; i<=V; ++i) for(int v : adj[i])
        if(leader[i]!=leader[v] && !st.count({leader[i],leader[v]}))
            st.insert({leader[i],leader[v]}), newadj[leader[i]].push_back(leader[v]);

    for(int i=1; i<=lead; ++i) for(int v : newadj[i])
        cout << i << ' ' << v << endl;

    return 0;
}
