#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long
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
    string str;
    while (cin >> str) {
        int sc[2] = {0};
        bool f, s, t;

        bool pl = 0;
        int kill = 0;
        f = s = t = 0;
        for (auto c : str) {
            switch (c) {
                case 'O':
                    kill++;
                    if (kill >= 3){
                        pl = !pl;
                        kill = 0;
                        t=s=f=0;
                    }
                    break;
                case 'K':
                    kill++;
                    if (kill >= 3){
                        pl = !pl;
                        kill = 0;
                        t=s=f=0;
                    }
                    break;
                case 'W':
                    if (f) {
                        if (s) {
                            if (t) {
                                sc[pl] += 1;
                            } else {
                                t = 1;
                            }
                        } else {
                            s = 1;
                        }
                    } else {
                        f = 1;
                    }
                    break;
                case 'S':
                    sc[pl] += t;
                    t = s;
                    s = f;
                    f = 1;
                    break;
                case 'D':
                    sc[pl] += t;
                    sc[pl] += s;
                    t = f;
                    s = 1;
                    f = 0;
                    break;
                case 'T':
                    sc[pl] += t;
                    sc[pl] += s;
                    sc[pl] += f;
                    t = 1;
                    s = 0;
                    f = 0;
                    break;
                case 'H':
                    sc[pl] += t;
                    sc[pl] += s;
                    sc[pl] += f;
                    sc[pl] += 1;
                    t=s=f=0;
                    break;
            }
        }
        cout << sc[0] << " " << sc[1] << endl;
    }
    return 0;
}
