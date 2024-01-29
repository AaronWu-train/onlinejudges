#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll    long long
#define pb    push_back
#define endl  '\n'
#define AI(x) begin(x), end(x)
#ifdef DEBUG
#define debug(args...) LKJ("\033[1;32m[ " + string(#args) + " ]\033[0m", args)
template <class I>
void LKJ(I &&x) {
    cerr << x << '\n';
}
template <class I, class... T>
void LKJ(I &&x, T &&...t) {
    cerr << x << ", ", LKJ(t...);
}
template <class I>
void OI(I a, I b) {
    while (a < b) cerr << *a << " \n"[next(a) == b], ++a;
}
#else
#define debug(...) 0
#define OI(...)    0
#endif
#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

signed main() {
    _ string s;
    cin >> s;
    int         n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
    ll sum = 0, s1 = 0, s2 = 0;
    for (auto &i : a) {
        sum += i;
        if (i == 1 || i == 4 || i == 7) s1++;
        if (i == 2 || i == 5 || i == 8) s2++;
    }
    if (sum % 3 == 0) {
        for (int i = 0; i < n - 1; ++i) cout << a[i] << "+";
        cout << a[n - 1] << endl;
    } else if (sum % 3 == 1) {
        if (s2 < 1) {
            if (s1 < 2) {
                cout << "NO" << endl;
                return 0;
            } else {
                int s1c = 0;
                for (int i = 0; i < n; ++i) {
                    if ((a[i] == 1 || a[i] == 4 || a[i] == 7) && s1c < 2) {
                        cout << "-";
                        s1c++;
                    } else
                        cout << "+";
                    cout << a[i];
                }
            }
        } else {
            int s2c = 0;
            for (int i = 0; i < n; ++i) {
                if ((a[i] == 2 || a[i] == 5 || a[i] == 8) && s2c < 1) {
                    cout << "-";
                    s2c++;
                } else
                    cout << "+";
                cout << a[i];
            }
        }
    } else if (sum % 3 == 2) {
        if (s1 >= 1) {
            int s1c = 0;
            for (int i = 0; i < n; ++i) {
                if ((a[i] == 1 || a[i] == 4 || a[i] == 7) && s1c<1) {
                        cout << "-";
                        s1c++;
                    }
                else
                    cout << "+";
                cout << a[i];
            }
        } else if (s2 >= 2) {
            int s1c = 0;
            for (int i = 0; i < n; ++i) {
                if ((a[i] == 2 || a[i] == 5 || a[i] == 8) && s1c < 2) {
                    cout << "-";
                    s1c++;
                } else
                    cout << "+";
                cout << a[i];
            }

        } else
            cout << "NO" << endl;
    }

    return 0;
}
