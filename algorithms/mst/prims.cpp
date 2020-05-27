#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;
const int mxE = 1e5+5;

int V, E, a, b, x;
vector<array<int, 2>> adj[mxV];
bool vis[mxV];

int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b >> x, adj[a].push_back({x,b}), adj[b].push_back({x,a});
    
    priority_queue<array<int, 3>> pq;
    for(auto v : adj[1]) pq.push({v[0], 1, v[1]});

    vector<array<int, 3>> mst;
    
    vis[1] = true;
    int dist = 0;
    while(!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int u = curr[2];

        if(vis[u]) continue;
        vis[u] = true;

        mst.push_back(curr);
        dist+=curr[0];

        for(auto v : adj[u])
            if(!vis[v[1]]) pq.push({v[0], u, v[1]});
    }

    for(auto v : mst) {
        for( auto det : v )
            cout << det << ' ';
        cout << endl;
    }

    return 0;
}
