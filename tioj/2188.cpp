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
    string k;
    cin >> k;
    string ans = "";
    int count = 0;
    for (auto i : k) {
        if (i>='0' && i<='9') {
            count = 10*count + (i-'0');
        }else{
            if (count == 0)ans+=i;
            else while(count--)ans+=i;
            count = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
