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

vector<int>F(20005,0);
signed main() {_
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        int q;
        cin >> q;
        while (q--) {
            string pat;
            cin >> pat;
            int pos = F[0] = -1;
            for (int i = 1; i < pat.size(); ++i) {
                while (pos!=-1 && pat[i] != pat[pos+1]) {
                    pos = F[pos];
                }
                if (pat[pos+1] == pat[i]) pos++;
                F[i] = pos;
            }
//            OI(F.begin(), F.begin()+7);
            pos = -1;
            int ans = 0;
            for (int i = 0; i < x.size(); ++i) {
                while (pos!=-1 && pat[pos+1] != x[i]) {
                    pos = F[pos];
                }
                if (pat[pos+1] == x[i]) pos++;
                if (pos == pat.size()-1) {
                    ans++;
                    pos = F[pos];
                }
            }
            cout << ans << endl;
            
        }
    }
    return 0;
}
