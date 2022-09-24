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
vector <int> arr;


int n, qsize;
struct qur{
	int id; 
	int l;
	int r;
	int ans;
};

vector<qur> Q;
int curs;
int cnt[(int)2e5+5];
int cc[(int)2e5+5];
int x = 0;

void add(int i){
	cc[ cnt[arr[i]] ]--;
	cnt[arr[i]]++;
   	cc[cnt[arr[i]]]++;
	x = max(x, cnt[arr[i]]);
}

void del(int i) {
	cc[ cnt[arr[i]] ]--;
	cnt[arr[i]]--;
	cc[ cnt[arr[i]] ]++;
	if (cc[x] == 0) x--;
}

int main(){_
	cin >> n >> qsize;
	arr.resize(n);
	for (auto &i : arr) cin >> i;
	Q.resize(qsize);
	for (int i = 0; i < qsize; ++i) {
		Q[i].id = i;
		cin >> Q[i].l >> Q[i].r;
		Q[i].l--;
		Q[i].r--;
	}		
	int k = ceil(sqrt(n));
	sort(Q.begin(), Q.end(), [&](auto &a, auto &b) {
			if (a.l/k == b.l/k) return a.r < b.r;
			return a.l < b.l;
			});
	int curl = 0;
	int curr = -1;
	cc[0] = n;
	for (auto &u : Q) {
		while (curr < u.r) add(++curr);
		while (curl > u.l) add(--curl);
		while (curr > u.r) del(curr--);
		while (curl < u.l) del(curl++);
		debug(curl, curr, x);
		u.ans = x;
	}
	sort(Q.begin(), Q.end(), [](auto &a, auto &b) {
			return a.id < b.id;
			});	

	for (auto i : Q) cout << i.ans << endl;
	return 0;
}
