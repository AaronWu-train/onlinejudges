#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii;
#define AI(x) begin(x),end(x)
#define ff first
#define ss second
#ifdef DEBUG 
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif

int n;
vector<ll>v,d;
vector<ll>bit(100005);

int getid(int x){
    return lower_bound(AI(d),x)-d.begin()+1;
}

ll query(int ind) {
    ll ans = 0;
    for(;ind>0;ind-=(ind&-ind)){
        ans+=bit[ind];
    }
    return ans;
}

void modify(int ind, ll x) {
    for(;ind<=n;ind+=(ind&-ind)){
        bit[ind]+=x;
    }
}
int main(){
    while( cin >> n){
        v.clear();
        d.clear();
        bit.clear();
        bit.resize(n+5,0);
    for(int i = 0; i < n; ++i){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    d=v;
    sort(AI(d));
    for(int i = 1; i <= n; ++i){
        int ind = getid(v[i-1]);
        modify(ind,1);
        cout << i - query(ind)+1 << endl;
    }
    }
	return 0;
}
