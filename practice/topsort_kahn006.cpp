#include <bits/stdc++.h>

using namespace std;

int V, E, a,b,x;
const int mxV = 1e5+5;
const int mxE = 1e5+5;

vector<int> adj[mxV];
vector<int> topsort;
int in[mxV];

int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b), ++in[b];

    queue<int> qq;
    for(int i=1; i<=V; ++i) if(!in[i]) qq.push(i);
    while(!qq.empty()) {
        int u = qq.front(); qq.pop();
        topsort.push_back(u);
        for(int v : adj[u])
            if(!--in[v]) qq.push(v);
    }

    for(int u : topsort)
        cout << u << ' ';
    cout << endl;

    return 0;
}
