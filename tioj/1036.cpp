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
const int maxn = 1e7+5;

int pre[maxn] = {0};
bitset<maxn> isprime;

signed main() {_
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for (ll i = 2; i < maxn; ++i) {
        if (isprime[i]) {
            for (ll j = i; j * i < maxn; ++j) {
                isprime[i*j] = 0;
            }
        }
    }
    for (int i = 2; i < maxn; ++i) {
        pre[i] = pre[i-1] + isprime[i];
    }
    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        cout << pre[n] << endl;
    }
    
    return 0;
}
