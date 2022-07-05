#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long int
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

signed main() {
    double a1,a2,b1,b2,x,y;
    cin >> a1 >> a2 >> b1 >> b2;
    x = (b2-b1)/(a1-a2);
    y = a1 * x + b1;
    
    x *= 100;
    y *= 100;
    x = round(x);
    y = round(y);
    if (x == -0.0) x = 0.0;
    if (y == -0.0) y = 0.0;
    cout <<fixed << setprecision(2) << x/100.0 << endl << y/100.0 << endl;
    
    return 0;
}
