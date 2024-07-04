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

int dfs(int x, int swap, vector<int>&State, vector<int> child[]) {
    State[x] = (State[x]+swap)%2;
    int ret = 0;
    if (State[x]==0) {
        swap++;
        ret++;
        State[x] = 1;
    }
    for (auto i : child[x]) {
        ret+=dfs(i, swap, State, child);
    }
    return ret;
}

signed main() {_
    int n;
    cin >> n;
    vector<int>State(n);
    string a;
    cin >> a;
    for (int i = 0; i < n; ++i) {
        State[i] = (a[i]=='W');
    }
    vector<int>child[n];
    for (int i = 1; i < n; ++i) {
        int temp;
        cin >> temp;
        temp--;
        child[temp].push_back(i);
    }
//    vector<bool>visit(n);
    cout << dfs(0, 0, State, child) << endl;
    
    return 0;
}
