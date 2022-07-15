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
int deap, yun, leaf;
int fun(string s, int i, int dd) {
    debug(i);
    deap = max(deap, dd);
    int count = 0;
    int ans = 0;
    for (int j = i; j < s.size(); j++) {
        if (s[j] == '*') {
            ans++;
            leaf++;
            continue;
        }
        else if (s[j] == '(') {
            count++;
            ans++;
            j = fun(s, j+1, dd+1);
        }
        yun = max(yun, ans);
        if (s[j] == ')') count--;
        if (count < 0) return j;
    }
    return s.size()-1;
}

signed main() {_
    string n;
    while (cin >> n) {
        leaf = deap = yun = 0;
        fun(n, 0, 1);
        cout << leaf << " ";
        cout << deap << " ";
        cout << yun << endl;
    }
    return 0;
}
