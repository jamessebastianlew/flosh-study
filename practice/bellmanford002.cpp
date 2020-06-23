#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;
const int mxE = 1e5+5;

template<typename T>
void amin(T& a, T b) {a=a<b?a:b;}

int V, E, a,b,x;
int start;

array<int, 3> edges[mxE];
int dist[mxV];

int main() {
    cin >> V >> E >> start;
    for(int i=0; i<E; ++i) for(int j=0; j<3; ++j)
        cin >> edges[i][j];

    memset(dist, 0x3f, sizeof(dist)); dist[start]=0;

    for(int i=0; i<V-1; ++i) for(auto e : edges)
        amin(dist[e[1]], dist[e[0]] + e[2]);

    for(int i=1; i<=V; ++i) cout << dist[i] << ' ';
    cout << endl;

    return 0; 
}
