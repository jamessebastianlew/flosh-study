#include <bits/stdc++.h>

using namespace std;

int V, E, a,b,x;
const int mxV = 1e5+5;
const int mxE = 1e5+5;

vector<array<int,2>> adj[mxV]; // x, v
int dist[mxV];
bool vis[mxV];

int main() {
    int start;
    cin >> V >> E >> start;
    for(int i=0; i<E; ++i)
        cin >> a >> b >> x, adj[a].push_back({x,b});

    priority_queue<array<int,2>> qq; // dist, v
    qq.push({0, start});

    while(!qq.empty()) {
        auto u = qq.top(); qq.pop();

        if(vis[u[1]]) continue;
        vis[u[1]] = true;
        dist[u[1]] = u[0];
        
        for(auto v : adj[u[1]])
            if(!vis[v[1]]) qq.push({v[0]+u[0], v[1]});
    }

    for(int i=1; i<=V; ++i)
        cout << dist[i] << ' ';
    cout << endl;
    return 0;
}
