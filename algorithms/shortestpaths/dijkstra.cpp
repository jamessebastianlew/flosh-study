#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;
const int mxE = 1e5+5;

int V, E, a, b, x, starting;
vector<array<int, 2>> adj[mxV]; // v, val
bool vis[mxV];
int dist[mxV];

int main() {
    cin >> V >> E >> starting;
    for(int i=0; i<E; ++i) {
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
        adj[b].push_back({a, x});
    }

    queue<array<int, 2>> qq;
    qq.push({0, starting});
    while(!qq.empty()) {
        array<int,2> curr = qq.front();
        int u = curr[1], val = curr[0];
        qq.pop();
        
        if(vis[u]) continue;
        vis[u] = true, dist[u] = val;

        for(array<int, 2> v : adj[u])
            if(!vis[v[0]]) qq.push({v[1]+dist[u], v[0]});
    }
    
    for(int i=1; i<=V; ++i)
        cout << dist[i] << ' ';
    cout << endl;

    return 0;
}
