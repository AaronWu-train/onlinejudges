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
    int n;
    cin >> n;
    vector<int>arr(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a,b;
        cin >> a >> b;
        for (int j = 0; j < b; ++j) {
            a = arr[a];
        }
        cout << a << endl;
    }
    
    return 0;
}
