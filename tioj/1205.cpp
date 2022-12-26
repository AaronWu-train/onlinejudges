#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
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

struct pt{
    ll x,y;
    bool operator < (pt b){
        if(x == b.x)return y < b.y;
        return x < b.x;
    }
    bool operator > (pt b){
        if(x == b.x)return y > b.y;
        return x > b.x;
    }
    bool operator == (pt b){
        if(x-b.x == 0 && y-b.y == 0)return true;
        return false;
    }
    pt operator+(pt b) {return {x + b.x, y + b.y};} //向量相加
    pt operator-(pt b) {return {x - b.x, y - b.y};} //向量相減
    ll operator^(pt b) {return x * b.y - y * b.x;} //向量外積cross
    ll operator*(pt b) {return x * b.x + y * b.y;} //向量內積dot
};

bool cmp(pt a, pt b) {
	ll f1 = (a > pt{0, 0});
	ll f2 = (b > pt{0, 0});
	if (f1 != f2) return f1 > f2;
	return (a^b) > 0;
}


signed main(){_
	ll n;
	while(cin >> n && n) {
		vector<pt> arr(n);
		for (ll i = 0; i < n; ++i) {
			cin >> arr[i].x >> arr[i].y;
		}
		ll ans = 0;
		for (ll j = 0;j  < n; ++j) {
			vector<pt> temp;
			for (ll i = 0; i < n; ++i) {
				if(i != j) temp.pb(arr[i] - arr[j]); 
			}
			sort(AI(temp), cmp);
			
			vector<ll> cnt; // 每個角度的個數
			vector<pt> pp; // after remove same degs;
			pp.pb(temp[0]);
			cnt.pb(1);
			for (ll i = 1; i < temp.size(); ++i){
				ll cross = temp[i]^temp[i-1];
				ll dot = temp[i]*temp[i-1];
				if (cross==0 && dot >= 0) cnt.back()++;
				else {
					pp.pb(temp[i]);
					cnt.pb(1);
				}
			}	
			ll len = pp.size();
			for (ll i = 0; i < len; ++i) {
				pp.pb(pp[i]);
				cnt.pb(cnt[i]);
			}

			ll r = 0;
			for (ll i = 0; i < len; ++i) {
				while(r < i + len &&(pp[i]^pp[r]) >= 0 && (pp[i]*pp[r]) > 0) {
					r++;
				}	
				if((pp[i]^pp[r]) > 0 && (pp[i]*pp[r]) == 0)
					ans += cnt[i]*cnt[r];
			}
		}
		cout << ans << endl;
	}

	return 0;
}
