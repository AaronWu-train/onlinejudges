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

int gcd(int a, int b) {
    if (!a) return b;
    return gcd(b%a, a);
}

inline int hsh(vector<int> vec){
    int ans = 0;
    for(int v: vec)
        ans = ans * 50 + v;
    return ans;
}

signed main() {_
    int n;
//    while (cin >> n) {
            
    cin >> n;
        int siz[10] = {0};
        for (int i = 0; i < n; ++i) cin >> siz[i];
        int t;
        cin >> t;
        
        int sum = 0;
        bool flag = 0;
        int h = 0;

        for (auto i : siz) {
            sum += i;
            if (i >= t) flag = 1;
            h = gcd(h, i);
        }
        debug(h);
        if (!flag || t % h) {
            cout << -1 << endl;
            return 0;
        }
        
        
        map<int, bool> visited;
        queue<pair<vector<int>, int>> bfs;
        vector<int> g(n, 0);
        bfs.push({g, 0});
        visited[0] = 0;
        int ans = -1;
        
        while (!bfs.empty() && ans == -1) {
            auto [status, step] = bfs.front();
            bfs.pop();
            for (auto i : status) {
                if (i == t) {
                    ans = step;
                    break;
                }
            }
            if (ans != -1) break;
            
            // remove
            for (int i = 0; i < n; ++i) {
                auto temp = status;
                temp[i] = 0;
                if (!visited[hsh(temp)]) {
                    bfs.push({temp, step+1});
                    visited[hsh(temp)] = 1;
                }
            }
            
            // fill
            for (int i = 0; i < n; ++i) {
                auto temp = status;
                temp[i] = siz[i];
                if (!visited[hsh(temp)]) {
                    bfs.push({temp, step+1});
                    visited[hsh(temp)] = 1;
                }
            }
            
            // move
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == j) continue;
                    auto temp = status;
                    int k = siz[j] - temp[j];
                    if (k >= temp[i]) {
                        temp[j] += temp[i];
                        temp[i] = 0;
                    }else{
                        temp[j] = siz[j];
                        temp[i] -= k;
                    }
                    if (!visited[hsh(temp)]) {
                        visited[hsh(temp)] = 1;
                        bfs.push({temp, step+1});
                    }
                }
            }
            
        }


        cout << ans << endl;
//    }
    return 0;
}
