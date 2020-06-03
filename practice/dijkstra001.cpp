#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;

int start, V, E, a,b,x;
vector<array<int, 2>> adj[mxV];
bool vis[mxV];
int dist[mxV];

int main() {
    cin >> V >> E;
    cin >> start;
    for(int i=0; i<E; ++i)
        cin >> a >> b >> x, adj[a].push_back({x, b});

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> qq;
    qq.push({0, start});
    while(!qq.empty()) {
        array<int, 2> curr = qq.top(); qq.pop();
        if(vis[curr[1]]) continue;
        vis[curr[1]] = true; dist[curr[1]] = curr[0];
        for(array<int, 2> v : adj[curr[1]])
            if(!vis[v[1]]) qq.push({curr[0]+v[0], v[1]});
    }

    for(int i=1; i<=V; ++i)
        cout << dist[i] << ' ';
    cout << endl;
        
        
    return 0;
}
