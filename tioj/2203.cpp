#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifdef DEBUG
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 1e9+7;

inline ll mabs(ll x){
    return (x%mod+mod)%mod;
}
inline ll madd(ll x, ll y) {
    return (x%mod+y%mod)%mod;
}
inline ll mmul(ll x, ll y) {
    return (x%mod*y%mod)%mod;;
}


struct SegmentTree{
    struct node{
        ll mv2 = 0;
        ll mv = 0;
        ll vv = 0;
        ll m = 0
        ll v = 0;
        ll vtag = 0;
        ll mtag = 0;
        void addv(ll x) {
           
        }
    };
};



int main(){_


    return 0;
}
