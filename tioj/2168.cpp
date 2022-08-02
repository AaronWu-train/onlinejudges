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

signed main() {_
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        bool outflag = 1;
        for (auto j : arr) {
            bool flag = 0;
            for (auto k : j) {
                if (k == i) {
                    flag = 1;
                    break;
                }
            }
            outflag &= flag;
        }
        if (outflag) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 7122 << endl;
    
    return 0;
}
