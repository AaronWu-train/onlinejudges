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

unsigned int rng() {
    static unsigned int secret_key = 45510; //使用者的密碼
    secret_key *= 0xdefaced;
    secret_key = (secret_key<<8) + (secret_key>>24) + 1;
    return secret_key;
}
int main(int argc, char* argv[]) {
	for (int i = 0; i < 100000; ++i)debug(rng());
    int cnt1 = atoi(argv[1]), cnt2 = atoi(argv[2]), cnt3 = atoi(argv[3]);
    int m = atoi(argv[4]);
    //產生一筆測資時，執行參數 argv 會被拿來執行 main

    int n = cnt1 + cnt2 + cnt3;
    cout << n << " " << m << "\n";
    vector<pair<int, int>> edge;
    for (int i = 0;i < m;i++) {
        int type = rng()%3, u, v;
        if (type == 0) u = rng()%cnt1, v = cnt1 + rng()%cnt2;
        else if (type == 1) u = cnt1 + rng()%cnt2, v = cnt1+cnt2+rng()%cnt3;
        else u = cnt1+cnt2+rng()%cnt3, v = rng()%cnt1;
        if (rng()%2) swap(u, v);
        edge.push_back({u, v});
		debug(u, v);
    }
    vector<pair<int, int> > perm;
    for (int i = 1;i <= n;i++) perm.push_back({rng(), i});
    sort(perm.begin(), perm.end());
    srand(time(NULL));
    std::random_shuffle(edge.begin(), edge.end());  
    for (int i = 0;i < m;i++) {
        cout << perm[edge[i].first].second << " " << perm[edge[i].second].second << "\n";
    }
    return 0;
}
