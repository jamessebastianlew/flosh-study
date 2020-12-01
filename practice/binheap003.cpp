#include <bits/stdc++.h>

using namespace std;

int n;
const int mxn = 1e5+5;
int len;
int heap[mxn];

void shiftup(int x) {
    for(; x>1 && heap[x>>1] < heap[x]; x = x>>1) 
        swap(heap[x], heap[x>>1]);
}

int mx_child(int x) {
    return (x<<1|1)<=len?heap[x<<1]>heap[x<<1|1]?x<<1:x<<1|1: x<<1;
}
void shiftdown(int x) {
    int u = mx_child(x);
    for(; (x<<1) <= len && heap[x] < heap[u]; u=mx_child(x))
        swap(heap[u], heap[x]), x=u;
}

void insert(int x) {
    heap[++len] = x; shiftup(len);
}

int pop() {
    int temp = heap[1];
    heap[1] = heap[len--];
    shiftdown(1);
    return temp;
}

int a;
int main() {
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a, insert(a);
    for(int i=0; i<n; ++i) cout << pop() << ' ';
    cout << endl;

    return 0;
}
