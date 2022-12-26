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

struct point{
    int x,y;
    bool operator == (point b){
        if(x == b.x && y == b.y)return true;
        return false;
    }
    point operator - (point b){return {x - b.x , y - b.y};}
    point operator + (point b){return {x + b.x , y + b.y};}
    int operator ^ (point b){return (x * b.y - y * b.x);}
    int operator * (point b){return (x * b.x + y * b.y);}
};

bool onseg(point a,point b,point o){
    int cross = (a - o) ^ (b - o);
    int dot = (a - o) * (b - o);
    return (cross == 0) && (dot <= 0);
}
 
 
int ori(point a, point b, point o) {
	ll cross = (a-o)^(b-o);
	if (cross == 0) return 0;
	else if (cross > 0) return 1;
	else return -1;
}

bool banana(point a, point b, point c, point d){
	if (onseg(a, b, c) || onseg(a, b, d)) return 1;
	if (onseg(c, d, a) || onseg(c, d, b)) return 1;
	return (ori(a, b, c) * ori(a, b, d)<0 && 
			ori(c, d, a) * ori(c, d, b)<0);
}

signed main(){_
	int t;
	cin >> t;
	while(t--) {
		point a, b, c, d;
		cin >> a.x >> a.y;
		cin >> b.x >> b.y;
		cin >> c.x >> c.y;
		cin >> d.x >> d.y;

		cout << (banana(a,b,c,d) ? "YES":"NO") << endl; 
	}
}
