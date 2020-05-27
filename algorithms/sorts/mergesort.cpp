#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n,a,b,x;
int aa[mxN];
int temp[mxN];

void mergesort(int arr[], int l=0, int r=n) {
    if(r-l<2) return;
    int mid = (l+r)>>1;
    mergesort(arr, l, mid); mergesort(arr, mid, r);

    int i=l, j=mid, len=0;
    while(i<mid && j<r)
        if(arr[i]<arr[j]) temp[len++]=arr[i++];
        else temp[len++]=arr[j++];

    if(j<r) i=j, mid=r;
    for(; i<mid; ++i) temp[len++]=arr[i];

    for(int i=0; i<len; ++i) arr[i+l]=temp[i];
}

int main() {

    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    mergesort(aa);
    for(int i=0; i<n; ++i) cout << aa[i] << ' ';
    cout << endl;

    return 0;
}
