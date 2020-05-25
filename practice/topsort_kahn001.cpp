#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;
const int mxE = 1e5+5;
int V, E, a, b;
vector<int> adj[mxV];
int indegree[mxV];
int len;
int topsort[mxV];

int main() {

    cin >> V >> E;
    for(int i=0; i<E; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        ++indegree[b];
    }

    queue<int> qq;
    for(int i=1; i<=V; ++i)
        if(indegree[i]==0)
            qq.push(i);

    while(!qq.empty()) {
        int curr = qq.front(); qq.pop();
        topsort[len++] = curr;

        for(int v : adj[curr])
            if(!(--indegree[v]))
                qq.push(v);
    }

    for(int i=0; i<len; ++i)
        cout << topsort[i] << ' ';
    cout << endl;

    return 0;
}
