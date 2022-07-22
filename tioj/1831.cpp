#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long
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
const int maxn = 105;

signed main() {_
    int n, m, k;
    cin >> n >> m >> k;
    if (!k) { // mat
        vector<vector<int>>arr(n+1, vector<int>(n+1, 0));
        int a, b;
        string way;
        for (int i = 0; i < m; ++i) {
            cin >> a >> way >> b;
            if (way == "->") arr[a][b] = 1;
            if (way == "<-") arr[b][a] = 1;
            if (way == "<->") arr[a][b] = arr[b][a] = 1;
        }
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j < n; ++j) {
                cout << arr[i][j] << " ";
            }
            cout << arr[i][n] << endl;
        }
    }
    else {
        set<int>arr[n+5];
        int a, b;
        string way;
        for (int i = 0; i < m; ++i) {
            cin >> a >> way >> b;
            if (way == "->") arr[a].insert(b);
            if (way == "<-") arr[b].insert(a);
            if (way == "<->") {
                arr[a].insert(b);
                arr[b].insert(a);
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << i << " ->";
            if (arr[i].empty()) cout << " 0";
            else for (auto j : arr[i]) cout << " " << j;
            cout << endl;
        }
    }
    return 0;
}
