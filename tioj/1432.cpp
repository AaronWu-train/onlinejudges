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
int w, n;

bool check(int x, vector<int>&arr) {
    int k = 0;
    int cursum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > x) return 0;
        if (cursum + arr[i] <= x) cursum+=arr[i];
        else{
            k++;
            cursum = arr[i];
        }
    }
    return k<=w;
}

signed main() {_
    cin >> n >> w;
    while (w||n) {
        vector<int>arr(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }
        int l = 0, r = 1e8;
        while (l < r-1) {
            int mid = (l+r)/2;
//            debug(mid);
            if (check(mid,arr)){
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << endl;
        cin >> n >> w;
    }
    
    return 0;
}
