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
    while (n) {
        int sumn = 0;
        int maxn = 1;
        int minn = 10;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            maxn = max(maxn, temp);
            minn = min(minn, temp);
            sumn += temp;
        }
        cout << fixed << setprecision(2) << (double)(sumn-maxn-minn)/(n-2) << endl;
        cin >> n;
    }
    return 0;
}
