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
const int N = 1005;
int M = 1005;
int INF = 1000000005;
int n, m;
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
}pt[N];

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

int solve() {
	point cur;
	cin >> cur.x >> cur.y;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (onseg(pt[i], pt[i+1], cur) == 1) return -1;
		if(banana(pt[i],pt[i+1],cur,point{INF,cur.y}))sum++;
		point temp = pt[i].y > pt[i+1].y ? pt[i] : pt[i+1];
        if(temp.y == cur.y && temp.x > cur.x)sum--;
	}
	return sum;
}
signed main(){_
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> pt[i].x >> pt[i].y; 
	}	
	for (int j = 0; j < m; ++j) {
		int ans = solve();	
		if (ans == -1) cout << "BOUNDARY" << endl;
		else if (ans & 1) cout << "INSIDE" << endl;
		else cout << "OUTSIDE" << endl;
	}

	return 0;
}
