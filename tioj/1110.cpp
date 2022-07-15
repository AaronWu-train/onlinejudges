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
    int n,k;
    cin >> n;
    while (n--) {
        cin >> k;
        string s;
        cin >> s;
        int arr[26] = {0};
        for (auto &i : s) arr[i-'a']++;
        int k = *max_element(AI(arr));
        for (int i = 0; i < 26; ++i) {
            if (arr[i] == k) cout << (char)('a'+i);
        }
        cout << endl;
    }
    return 0;
}
