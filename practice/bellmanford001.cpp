#include <bits/stdc++.h>

using namespace std;

void amin(int& a, int b) { a=a<b?a:b; }
int V, E, a,b,x, start;
const int mxV = 1e5+5;
const int mxE = 1e5+5;

vector<array<int, 2>> adj[mxV];
array<int, 3> edges[mxE];
int dists[mxV];

int main() {

    memset(dists, 0x3f, sizeof(dists));
    cin >> V >> E;
    cin >> start;
    dists[start] = 0;
    for(int i=0; i<E; ++i)
        for(int j=0; j<3; ++j) cin >> edges[i][j];

    for(int i=0; i<V-1; ++i)
        for(int j=0; j<E; ++j)
            amin(dists[edges[j][1]], dists[edges[j][0]]+edges[j][2]);

    for(int i=1; i<=V; ++i)
        cout << dists[i] << ' ';
    cout << endl;
            
            
    return 0;
}
