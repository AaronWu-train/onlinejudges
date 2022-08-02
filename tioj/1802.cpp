#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long
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
const int maxn = 1e6+5;
int fa[maxn];
int ans[maxn];
vector<int> child[maxn];
bool visited[maxn];
set<int> unused;

struct BIT{
    int n;
    vector<int>arr;
    void init(int _n) {
        n = _n;
        arr.resize(n+5,0);
    }
    void modify(int i, int v) {
//        debug(i);
        for (; i <= n; i += (i&-i)) {
            arr[i] += v;
        }
    }
    
    int query(int i) {
        int ans = 0;
        for (; i>0; i -= (i & -i)) {
            ans += arr[i];
        }
        return ans;
    }
    
}bit;


void dfs(int i, int top) {
    visited[i] = 1;
    int mxc = 0;
    if (ans[i]) top = ans[i];
    for (auto j : child[i]) {
        if (!visited[j]) {
            dfs(j, top-1);
            mxc = max(mxc, ans[j]);
        }
    }
//    debug(i, top);
    if (!ans[i]) bit.modify(top, 1);
    return;
}

void dfs2(int i, int top) {
    visited[i] = 1;
    int mxc = 0;
    if (ans[i]) top = ans[i];
    for (auto j : child[i]) {
        if (!visited[j]) {
            dfs2(j, top-1);
            mxc = max(mxc, ans[j]);
        }
    }
    if (ans[i])return;
    int chsz = bit.query(top-1);
    auto it = unused.begin();
    for (int j = 0; j < chsz; ++j, ++it);
    if (next(it) == unused.upper_bound(top)) {
        ans[i] = *(it);
        unused.erase(it);
        bit.modify(top, -1);
    }
}

signed main() {_
    int n;
    cin >> n;
    bit.init(n);
    int boss = 1;
    for (int i = 1; i <= n; ++i) {
        unused.insert(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> fa[i] >> ans[i];
        if (i == fa[i]) boss = i;
        else child[fa[i]].push_back(i);
        if (ans[i])unused.erase(ans[i]);
    }
    ans[boss] = n;
    dfs(boss, n);
    fill(visited, visited+n+5, 0);
    dfs2(boss, n);
    
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }
    
    return 0;
}
