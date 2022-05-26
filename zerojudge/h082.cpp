#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii;
#define AI(x) begin(x),end(x)
#define ff first
#define ss second
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif

int main(){
    int n, m;
    cin >> n >> m;
    vector <ll> S(n+5);
    vector <ll> T(n+5);
    for (int i = 1; i <= n; ++i) cin >> S[i];
    for (int i = 1; i <= n; ++i) cin >> T[i];
    vector<int>losecount(n+5,0);
    queue<int>sur;
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        sur.push(temp);
    }

    while(sur.size()>1) {
        queue<int>winner;
        queue<int>loser;
        // cerr << "-------\n\n";
        while(sur.size()>1) {
            int x = sur.front();
            sur.pop();
            int y = sur.front();
            sur.pop();
            ll a = S[x], b = T[x];
            ll c = S[y], d = T[y];
            if(a*b >= c*d) {
                S[x] = a + c*d/(2*b);
                T[x] = b + c*d/(2*a);
                S[y] = c + c/2;
                T[y] = d + d/2;
                losecount[y]++;
                if(losecount[y]<m) loser.push(y);
                winner.push(x);
            } else {
                S[x] = a + a/2;
                T[x] = b + b/2;
                S[y] = c + a*b/(2*d);
                T[y] = d + a*b/(2*c);
                losecount[x]++;
                if(losecount[x]<m) loser.push(x);
                winner.push(y);
            }
        }
        // cerr << "\n";
        OI(AI(losecount));

        if(!sur.empty()) {
            winner.push(sur.front());
            sur.pop();
        }
        // cerr << "winner :";
        while(!winner.empty()){
            sur.push(winner.front());
            // cerr << winner.front() << " ";
            winner.pop();
        }
        // cerr << endl << "loser: ";
        while(!loser.empty()){
            sur.push(loser.front());
            // cerr << loser.front() << " ";
            loser.pop();
        }
        // cerr << endl;
    }
    cout << sur.front() << endl;
    return 0;
}
