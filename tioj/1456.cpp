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
    int n,m;
    while (cin >> n >> m) {
        vector<int>count(n+5,0);
        vector<int>adj[1005];
        for (int i = 0; i < m; ++i) {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            count[b]++;
        }
        bool flag = 1;
        vector<int>arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (auto i : arr) {
            if (count[i]) {
                flag = 0;
                break;
            }
            for (auto j : adj[i]) {
                count[j]--;
            }
        }
        cout << (flag? "YES" : "NO") << endl;
    }
    
    
    
    return 0;
}
