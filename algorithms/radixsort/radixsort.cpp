#include <bits/stdc++.h>

using namespace std;

int last(int nm, int bits) {
    return ((nm>>bits)<<bits)^nm;
}

void radix_sort(int* arr, int n, int bits) {
    int total = sizeof(int)*8;
    int lcnt = 1<<bits;
    int* cnt = new int[lcnt];
    int* temp = new int[n];

    while(total > 0) {
        memset(cnt, 0, sizeof(int) * lcnt);
        for(int i=0; i<n; ++i) ++cnt[last(arr[i]>>(32-total), bits)];
        for(int i=1; i<lcnt; ++i) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; --i) temp[--cnt[last(arr[i]>>(32-total), bits)]] = arr[i];
        for(int i=0; i<n; ++i) arr[i] = temp[i];

        total -= bits;
    }

    delete[] cnt;
    delete[] temp;
}

const int mxn = 1e5+5;
int n, bits;
int aa[mxn];

int main() {
    cin >> n >> bits;

    for(int i=0; i<n; ++i) cin >> aa[i];
    radix_sort(aa, n, bits);
    for(int i=0; i<n; ++i) cout << aa[i] << ' ';
    cout << endl;

    return 0;
}
