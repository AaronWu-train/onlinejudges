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

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}


signed main() {_
    int n;
    while (cin >> n) {
        int a;
        cin >> a;
        for (int i = 0; i < n-1; ++i) {
            int b;
            cin >> b;
            a = gcd(a, b);
        }
        cout << a << endl;
    }
    return 0;
}
