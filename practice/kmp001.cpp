#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+5;

int lps[mxn];

int main() {
    string s, t;
    cin >> s >> t;
    
    const int n = s.size();
    const int m = t.size();

    int len = 0;
    for(int i=1; i<n; ++i) {
        while(len > 0 and s[i] != s[len]) len = lps[len-1];
        if(s[i] == s[len]) ++len;
        lps[i] = len;
    }

    int cnt = 0;
    for(int i=0; i<m; ++i) {
        while(len > 0 and t[i] != s[len]) len = lps[len-1];
        if(t[i] == s[len]) ++len;
        if(len == n) ++cnt, len = lps[len-1];
    }
    
    cout << cnt << endl;

    return 0;
}
