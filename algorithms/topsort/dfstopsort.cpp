#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int mxV=1000;
const int mxE=100000;

int n;
int V, E;
int temp_one, temp_two;


vector<int> adj[mxV+1];

bool visited[mxV+1];
vector<int> top_sort;

void dfs(int curr) {
    if(visited[curr])
        return;
    visited[curr] = true;
    for(int node : adj[curr])
        if(!visited[node]) dfs(node);
    top_sort.push_back(curr);
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> temp_one >> temp_two,
            adj[temp_one].push_back(temp_two);

    for(int i=1; i<=V; ++i)
        dfs(i);

    n=top_sort.size();
    for(int i=0; i< (n>>1); ++i)
        swap(top_sort[i], top_sort[n-i-1]);

    for(int node : top_sort)
        cout << node << ' ';
    cout << endl;

    return 0;

}

