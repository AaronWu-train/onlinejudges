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

struct KMF{
    int strength;
    int id;
    string st;
};

vector<KMF> arr;
signed main() {_
    int n;
    while (cin >> n) {
        arr.clear();
        for (int i = 0; i < n; ++i) {
            string temp;
            cin >> temp;
            int sum = 0;
            for (auto i : temp) sum += i - '0';
            arr.push_back({sum, i, temp});
        }
        sort(AI(arr), [](auto &a, auto &b) {
            if (a.strength != b.strength) return a.strength < b.strength;
            return a.id < b.id;
        });
        for (auto &i : arr) {
            cout << i.st << " ";
        }
        cout << endl;
    }
    return 0;
}
