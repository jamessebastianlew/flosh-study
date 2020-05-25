#include <bits/stdc++.h>

using namespace std;

const int mxV = 1001;
const int mxE = 100001;

int n, V, E;
int a, b, x;
int temp_one, temp_two;

vector<int> adj[mxV];
int len;
int topsort[mxV];
int indeg[mxV];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for(int i=0; i<E; ++i) {
        cin >> a >> b, adj[a].push_back(b);
        ++indeg[b];
    }

    queue<int> qq;
    for(int i=1; i<=V; ++i)
        if(!indeg[i]) qq.push(i);

    while(!qq.empty()) {
        int curr = qq.front();
        qq.pop();

        topsort[len++]=curr;
        for(int node : adj[curr])
            if(!(--indeg[node])) qq.push(node);
    }

    for(int i=0; i<len; ++i)
        cout << topsort[i] << ' ';
    cout << endl;





    return 0;
}
