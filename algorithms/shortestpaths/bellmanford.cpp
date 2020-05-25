#include <bits/stdc++.h>

using namespace std;

void amin(int& a, int b) { a=a<b?a:b; }

int V, E, a, b, x, starting;
const int mxV = 1e5+5;
const int mxE = 1e5+5;

array<int, 3> edges[mxE];
int dist[mxV];

int main() {

    cin >> V >> E >> starting;
    for(int i=0; i<E; ++i)
        for(int j=0; j<3; ++j)
            cin >> edges[i][j];

    memset(dist, 0x3f, sizeof(dist));
    dist[starting] = 0;
    for(int i=0; i<V-1; ++i)
        for(array<int, 3> edge : edges) {
            amin(dist[edge[0]], dist[edge[1]]+edge[2]);
            amin(dist[edge[1]], dist[edge[0]]+edge[2]);
        }

    for(int i=1; i<=V; ++i)
        cout << dist[i] << ' ';
    cout << endl;

    return 0;
}
