#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;
int V, E, a,b,x;

vector<int> adj[mxV];
int indegree[mxV];
vector<int> topsort;


int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b), ++indegree[b];

    queue<int> qq;
    for(int i=1; i<=V; ++i)
        if(!indegree[i]) qq.push(i);

    while(!qq.empty()) {
        int u = qq.front(); qq.pop();
        topsort.push_back(u);
        for(int v : adj[u])
            if(!(--indegree[v])) qq.push(v);
    }

    for(int v : topsort)
        cout << v << ' ';
    cout << endl;

    return 0;
}
