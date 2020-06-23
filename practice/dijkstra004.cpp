#include <bits/stdc++.h>

using namespace std;

const int mxv = 1e5+5;

int V,E,a,b,x,start;
vector<array<int,2>> adj[mxv];

bool vis[mxv];
int dist[mxv];
int main() {

    cin >> V >> E >> start;
    for(int i=0; i<E; ++i) 
        cin >> a >> b >> x, adj[a].push_back({x,b});

    priority_queue<array<int,2>> qq;
    qq.push({0,start});

    while(!qq.empty()) {
        array<int,2> t = qq.top(); qq.pop();
        int u = t[1], d = t[0];
        
        if(vis[u]) continue;
        vis[u] = true;

        dist[u] = d;
        for(auto v : adj[u])
            if(!vis[v[1]]) qq.push({v[0]+d, v[1]});
    }

    for(int i=1; i<=V; ++i) cout << dist[i] << ' ';
    cout << endl;

    return 0;
}
