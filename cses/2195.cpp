#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
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
    int x,y;
    bool operator == (pt b){
        if(x == b.x && y == b.y)return true;
        return false;
    }
    pt operator - (pt b){return {x - b.x , y - b.y};}
    pt operator + (pt b){return {x + b.x , y + b.y};}
    int operator ^ (pt b){return (x * b.y - y * b.x);}
    int operator * (pt b){return (x * b.x + y * b.y);}
};

bool onseg(pt a,pt b,pt o){
    int cross = (a - o) ^ (b - o);
    int dot = (a - o) * (b - o);
    return (cross == 0) && (dot <= 0);
}
 
 
int ori(pt a, pt b, pt o) {
	ll cross = (a-o)^(b-o);
	if (cross == 0) return 0;
	else if (cross > 0) return 1;
	else return -1;
}

bool banana(pt a, pt b, pt c, pt d){
	if (onseg(a, b, c) || onseg(a, b, d)) return 1;
	if (onseg(c, d, a) || onseg(c, d, b)) return 1;
	return (ori(a, b, c) * ori(a, b, d)<0 && 
			ori(c, d, a) * ori(c, d, b)<0);
}

signed main(){_
	int n;
	cin >> n;
	vector<pt> arr(n);
	for (auto &i : arr) cin >> i.x >> i.y;
	sort(AI(arr), [](auto a, auto b){
			return a.x < b.x;
			});
	vector<pt> hull;
	hull.pb(arr[0]);
	hull.pb(arr[1]);	
	for (int i = 2; i < n; ++i) {
		while (hull.size() > 2 && ((arr[i]-hull[hull.size()-2])^
				(arr[i]-hull[hull.size()-2])) > 0) {
			hull.pop_back();
		}
		hull.pb(arr[i]);
	}
	int len1 = hull.size();
	reverse(arr.begin(), arr.end());
}
