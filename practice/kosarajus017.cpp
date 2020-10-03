#include <bits/stdc++.h>

typedef long long ll;

#define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#define cio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void amod(T a, T b) { return a>=b?a-b:a; }

using namespace std;

int a, b, x;
int main() {
    cin >> a >> x >> b;

    while( !(a==0 && b ==0) ) {
        if(x=='W' && a-b < -200)
            cout << "Not allowed" << endl;
        else if(x=='W')
            cout << a-b << endl;
        else
            cout << a+b << endl;
        cin >> a >> x >> b;
    }

    return 0;
}
