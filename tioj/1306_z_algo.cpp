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

int z[20005] = {0};
signed main() {_
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        int q;
        cin >> q;
        while (q--) {
            string p;
            cin >> p;
            string s = p + "$" + x;
            int l = 0, r = 0;
            int ans = 0;
            for (int i = 1; i < s.size(); ++i) {
                int len = 0;
                if (i <= r) len = min(z[i-l], r-i+1);
                while (i+len < s.size() && s[i+len]==s[len]) len++;
                z[i] = len;
                if (len == p.size()) ans++;
                if (i + len - 1 > r) {
                    l = i;
                    r = i + len - 1;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
