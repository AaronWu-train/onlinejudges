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
const int maxn = 100005;
int n;
vector<ll>pos;
vector<ll>fish;

bool check(ll x) {
    ll more = fish[0] - x;
    for (int i = 1; i < n; ++i) {
        if (more > pos[i] - pos[i-1]) {
            more -= pos[i] - pos[i-1];
            more += fish[i] - x;
        }
        else if (more < 0) {
            more -= pos[i] - pos[i-1];
            more += fish[i] - x;
        }
        else more = fish[i] - x;
    }
    
//    debug(x, more);
    return more >= 0;
}

signed main() {_
    while (cin >> n) {
        pos.clear();
        fish.clear();
        pos.resize(n,0);
        fish.resize(n,0);
        ll l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            cin >> pos[i] >> fish[i];
            r = max(r, fish[i]);
        }
        r++;
        while (l < r-1) {
            ll mid = l + (r - l)/2;
            if (check(mid)) {
                l = mid;
            }
            else r = mid;
        }
        cout << l << endl;
    }
    return 0;
}
