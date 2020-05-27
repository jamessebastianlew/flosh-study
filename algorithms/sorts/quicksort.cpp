#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n;
int aa[mxN];

void quicksort(int arr[], int l=0, int r=n) {
    if(r-l<2) return;

    int piv = arr[r-1], start = l;
    for(int i=l; i<r; ++i)
        if(arr[i] < piv) swap(arr[start++], arr[i]);
    swap(arr[start], arr[r-1]);

    quicksort(arr, l, start); quicksort(arr, start+1, r);
}


int main() {

    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    quicksort(aa);
    for(int i=0; i<n; ++i) cout << aa[i] << ' ';
    cout << endl;

    return 0;
}
