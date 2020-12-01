#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+5;
int lps[mxn];
string s;

int main() {
    cin >> s;
    const int n = s.size();
    lps[0] = 0;
    int len = 0;
    for(int i=1; i<n; ++i) {
        while(len > 0 and s[i] != s[len]) len = lps[len-1];
        if(s[i] == s[len]) ++len;
        lps[i] = len;
    }

    string t;
    cin >> t;
    const int m = t.size();

    len = 0;
    int cnt = 0;
    for(int i=0; i<m; ++i) {
        while(len > 0 and t[i] != s[len]) len = lps[len-1];
        if(t[i] == s[len]) ++len;
        if(len == n) ++cnt, len = lps[len-1];
    }
    
    cout << cnt << endl;

    return 0;
}
