#pragma GCC optimize("Ofast")
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
    ll n,m;
    cin >> n >> m;
    vector<ll>arr(n+5);
    for (int i = 1 ; i <= n; i++) {
        cin >> arr[i];
    }
    ll pre[4][1000005]={0};
    for (int i = 0; i < m; ++i) {
        int l,r,d;
        cin >> l >> r >> d;
        pre[0][l]+=d;
        pre[0][r+1]-=d;
        pre[2][r+1]-=(r-l+1)*d;
    }
    
//    OI(pre[0],pre[0]+n+3);
    for (int i = 1; i <= n+1; i++) {
        pre[1][i] = pre[1][i-1]+pre[0][i];
    }
//    OI(pre[1],pre[1]+n+3);
//    OI(pre[2],pre[2]+n+3);

    for (int i = 1; i <= n+1; i++) {
        pre[3][i] = pre[3][i-1]+pre[1][i]+pre[2][i];
    }
//    OI(pre[3],pre[3]+n+3);
 
    for (int i = 1; i <=n; ++i) {
        cout << pre[3][i]+arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
