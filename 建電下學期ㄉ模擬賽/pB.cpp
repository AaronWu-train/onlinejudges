#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

signed main() {_
    int val[5];
    int k;
    for (int i = 1; i <=3 ; i++) cin >> val[i];
    cin >> k;
    k-=val[1];
    k-=val[2];
    k-=val[3];
    if(k<0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
//    debug(k);
    bool dp[5][(int)1e6+5] = {0};
    vector<vector<vector<int>>> source(5,vector<vector<int>>((int)1e6+5,vector<int>(3)));
    dp[0][0] = 1;
    source[0][0] = {1,1,1};
    for (int i = 1; i <= 3; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j>=val[i] && dp[i][j-val[i]] && !dp[i-1][j]) {
                dp[i][j] = 1;
                source[i][j] = source[i][j-val[i]];
                source[i][j][i-1]++;
//                debug(i,j);
            }
            else if (j>=val[i] && dp[i][j-val[i]] && dp[i-1][j]){
                dp[i][j] = 1;
                auto tem = source[i][j-val[i]];
                tem[i-1]++;
                source[i][j] = min(tem, source[i-1][j]);
                
            }
            else if (dp[i-1][j]) {
                dp[i][j] = 1;
                source[i][j] = source[i-1][j];
            }
        }
    }
    
    if (!dp[3][k]){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    else {
        cout << "POSSIBLE\n";
        for (int i = 0; i<3; ++i) {
            cout << source[3][k][i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
