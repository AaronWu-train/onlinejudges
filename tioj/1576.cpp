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

struct s{
    int a = 0,b = 0,c = 0;
    int prize(){
        return a*80+b*100+c*60;
    }
};

signed main() {_
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    s ans;
    for (int i = 0; i <= min(A,B); ++i) {
        int ta = A - i;
        int tb = B - i;
        s j = {min(ta,C), i, min(tb,D)};
        if (j.prize() > ans.prize()) ans = j;
    }
    cout << ans.a << " " << ans.b << " " << ans.c << endl << ans.prize() << endl;
    
    
    
    return 0;
}
