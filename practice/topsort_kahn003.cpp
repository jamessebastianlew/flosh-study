#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;

int V, E, a, b, x;
int len;
int indegree[mxV];
int topsort[mxV];
vector<int> adj[mxV];

int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b), ++indegree[b];

    queue<int> qq;
    for(int i=1; i<=V; ++i)
        if(!indegree[i]) qq.push(i);

    while(!qq.empty()) {
        int u = qq.front(); qq.pop();
        topsort[len++] = u;
        for(int v : adj[u])
            if(!(--indegree[v])) qq.push(v);
    }

    for(int i=0; i<len; ++i) cout << topsort[i] << ' ';
    cout << endl;

    return 0;
}
