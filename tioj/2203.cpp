#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
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
        ll m;
        ll v;
        ll mv;
        ll mvv;
        ll vv;
        ll len = 1;
        
        ll mtag = 0;
        ll vtag = 0;
        void init(ll _m, ll _v) {
            m = _m;
            v = _v;
            mv = m * v % mod;
            vv = v * v % mod;
            mvv = m * vv % mod;
        }
        
        void addm(ll x) {
            mtag += x;
            mvv += vv * x % mod;
            mv += v * x % mod;
            m += x * len % mod;
            
            mtag %= mod;
            mvv %= mod;
            mv %= mod;
            m %= mod;
        }

        void addv(ll x) {
            vtag += x;
            mvv += 2*mv % mod *x % mod + m*x %mod *x %mod;
            mv += m * x % mod;
            vv += 2*v*x %mod + mmul(x, mmul(x, len));
            v += x*len;
            
            vtag %= mod;
            mvv %= mod;
            mv %= mod;
            vv %= mod;
            v %= mod;
        }
        void merge(node &a, node &b) {
            m   = ( a.m   + b.m )% mod;
            v   = ( a.v   + b.v )% mod;
            mv  = ( a.mv  + b.mv )% mod;
            vv  = ( a.vv  + b.vv )% mod;
            mvv = ( a.mvv + b.mvv )% mod;
        }
    };
    int n;
    vector<node>arr;
    void init(int _n, vector<ll> &mass, vector<ll> &speed) {
        n = _n;
        arr.resize(2*n+5);
        for (int i = 0; i < n; ++i) {
            arr[i + n].init(mass[i], speed[i]);
            arr[i+n].len = 1;
        }
        for (int i = n-1; i > 0; --i){
            arr[i].merge(arr[i*2], arr[i*2+1]);
            arr[i].len = arr[i*2].len + arr[i*2+1].len;
        }
    }
    
    void pull(int x) {
        if (x == 1) return;
        pull(x/2);
        if (arr[x/2].vtag) {
            arr[x].addv(arr[x/2].vtag);
            arr[x^1].addv(arr[x/2].vtag);
            arr[x/2].vtag = 0;
        }
        if (arr[x/2].mtag) {
            arr[x].addm(arr[x/2].mtag);
            arr[x^1].addm(arr[x/2].mtag);
            arr[x/2].mtag = 0;
        }
    }
    
    void push(int x) {
        x >>= 1;
        while (x) {
            arr[x].merge(arr[x*2], arr[x*2+1]);
            x >>= 1;
        }
    }
    
    void speedModify(int l, int r, ll adv) {
        l+=n;
        r+=n;
        while (l < r) {
            if (l & 1) {
                pull(l);
                arr[l].addv(adv);
                push(l);
                l++;
            }
            if (r & 1) {
                --r;
                pull(r);
                arr[r].addv(adv);
                push(r);
            }
            l >>= 1;
            r >>= 1;
        }
    }
    
    void massModify(int l, int r, ll adm) {
        l+=n;
        r+=n;
        while (l < r) {
            if (l & 1) {
                pull(l);
                arr[l].addm(adm);
                push(l);
                l++;
            }
            if (r & 1) {
                --r;
                pull(r);
                arr[r].addm(adm);
                push(r);
            }
            l >>= 1;
            r >>= 1;
        }
    }
    
    ll query(int l, int r) {
        l+=n;
        r+=n;
        ll ans = 0;
        while (l < r) {
            if (l & 1) {
                pull(l);
                ans = (ans + arr[l].mvv) % mod;
                l++;
            }
            if (r & 1) {
                --r;
                pull(r);
                ans = (ans + arr[r].mvv) % mod;
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
}seg;

const ll modr2 = 500000004;

int main(){_
    int n, q;
    cin >> n >> q;
    vector<ll>mass(n);
    vector<ll>speed(n);
    for (auto &i : mass) cin >> i;
    for (auto &i : speed) cin >> i;
    seg.init(n, mass, speed);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            ll x;
            cin >> l >> r >> x;
            seg.massModify(l-1, r, x);
        }
        else if (type == 2) {
            int l, r;
            ll x;
            cin >> l >> r >> x;
            seg.speedModify(l-1, r, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            ll k = seg.query(l-1, r);
//            debug(k);
            cout << k * modr2 % mod << endl;
        }
        
    }

    return 0;
}
