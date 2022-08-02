#include <bits/stdc++.h>
#include "lib1926.h"
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
ll n, m;

bool check(ll y) {
    debug(y);
    int mxid = 0;
    for (int i = 1; i < n; ++i) {
        if (!Oshietekudasai(mxid, y, i, y)) {
            mxid = i;
        }
    }
    if (y == 0) {
        if (y == m-1 || Oshietekudasai(mxid, y, mxid, y+1)) {
            Report(mxid, y);
        }
        else return 0;
    }
    else if (y == m-1) {
        if (Oshietekudasai(mxid, y, mxid, y-1)) {
            Report(mxid, y);
        }
        return 1;
    } else {
//        debug( Oshietekudasai(mxid, y+1, mxid, y));
//        debug( Oshietekudasai(mxid, y-1, mxid, y));

        if (!Oshietekudasai(mxid, y-1, mxid, y) && !Oshietekudasai(mxid, y+1, mxid, y)) {
            Report(mxid, y);
        }
        return (Oshietekudasai(mxid, y-1, mxid, y));
    }
    return 0;
}

signed main() {_
    Init(&n, &m);
//    for (int i = 0; i < m; ++i) {
//        check(i);
//    }
    ll l = 0, r = m-1;
    while (l < r) {
        ll mid = l + (r - l)/2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    check(l);
    check(r);
    
    return 0;
}
