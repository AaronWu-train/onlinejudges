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

signed main() {
    vector<ll> len(45, 0);
    len[1] = 1;
    vector<int>arr={1};
    for (int i = 2; i <= 43; ++i) {
        vector<int> nv;
        int count = 1;
        int last = arr[0];
        for (int j = 1; j < arr.size(); ++j) {
            if (arr[j] == last) count++;
            else {
                nv.push_back(count);
                nv.push_back(last);
                count = 1;
                last = arr[j];
            }
        }
        nv.push_back(count);
        nv.push_back(last);
        arr = nv;
        len[i] = nv.size();
    }
    int n;
    scanf("%d", &n);
    while (n) {
        printf("%d %.6f\n",len[n], (double)len[n-1]/len[n]);
        scanf("%d", &n);
    }
    return 0;
}

