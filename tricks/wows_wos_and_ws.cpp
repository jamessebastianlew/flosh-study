#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //problem 1178B https://codeforces.com/problemset/problem/1178/B

    //try to think of combinatorial problems in a more broken down sense
    //for example, the problem can be done by using multiplication
    //but a better way to think is to think about what information you need
    //to generate what you want
    //
    //for example, in problem 1178B, it is good to think that at any specific
    //index, the number of 'wow's you can make if you are currently at a "vv"
    //is the number of 'wo's that you have had previously and can extend
    //
    //in order to get the number of 'wo's you must know the number of 'w's you've
    //had previously and whenever you get to an 'o', those 'w's can be extended by
    //an 'o'
    //
    //======   IN GENERAL    ============//
    //
    //THINK ABOUT THE INFORMATION THAT YOU NEED AT A CERTAIN POINT

    string s;
    cin >> s;
    ll wows, wos, prev_ws;
    for(int i = 0; i < (int)s.size(); ++i) {
        if(i && s[i]=='v' && s[i-1]=='v') ++prev_ws, wows+=wos;
        else if(s[i]=='o') wos+=prev_ws;
    }
    cout << wows;
    


    return 0;

}

