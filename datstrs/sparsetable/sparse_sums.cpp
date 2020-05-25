
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define poiu(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int st[1000][20];
int a[1000];

int n, K;
int q;
int temp_one, temp_two;

void initialise() {
    for(int i=0; i<n; ++i) 
        st[i][0]=a[i];

    for(int j=1; j<=K; ++j)
        for(int i=0; i+(1<<j)<=n; ++i)
            st[i][j]=st[i][j-1]+st[i+(1<<(j-1))][j-1];
}

int query(int L, int R) {
    int res = 0;
    for(int j=K; j>=0; --j)
        while(L+(1<<j)-1<=R)
            res+=st[L][j], L+=(1<<j);
    return res;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;
    for(int i=0; i<n; ++i)
        cin >> a[i];

    K=0;
    while((1<<(K+1))<=n)
        K+=1;

    initialise();

    for(int i=0; i<q; ++i) {
        cin >> temp_one >> temp_two;
        cout << query(temp_one, temp_two) << endl;
    }


    return 0;

}

