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

signed main() {_
    string mode;
    cin >> mode;
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
    while (mode != "END") {
        if (mode[0] == 'P') {
            int x;
            cin >> x;
            if (!small.empty()) {
                small.push(x);
                big.push(small.top());
                small.pop();
            } else big.push(x);
        }
        if (mode[0] == 'G') {
            if (!big.empty()) {
                cout << big.top() << endl;
                small.push(big.top());
                big.pop();
            }
            
        }
        if (mode[0] == 'E'){
            small = priority_queue<int>();
            big = priority_queue<int, vector<int>, greater<int>>();
        }
            
        cin >> mode;
    }
    return 0;
}
