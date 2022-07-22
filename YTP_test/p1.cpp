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
const ll maxn = 5005;
std::bitset<maxn> isprime;

signed main() {_
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for (ll i = 2; i < maxn; ++i) {
        if (isprime[i]) {
            for (ll j = i; i*j < maxn; ++j) {
                isprime[i*j] = 0;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = n; i >= 1; --i) {
        if (isprime[i] == isprime[n]) cout << i << " ";
    }
    cout << endl;
    return 0;
}
