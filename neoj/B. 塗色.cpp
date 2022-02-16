#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#define ll long long
#define debug(x) cerr << #x << " = " << (x) << endl;
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll c = 0;
    ll q;
    cin >> q;
    vector<pair<ll, ll>>sq;
    ll ans = 0;
    for (int count = 0; count < q; count++) {
        int type;
        ll x;
        cin >> type >> x;
        if (type == 1) {
            if (sq.empty()) {
                sq.push_back(make_pair(c, x));
                ans+=x*x;
                continue;
            }
            auto last = sq.rbegin();
            ll lastcx = last->first+last->second;
            if (lastcx< c+x) {
//                debug(count);
//                debug(lastcx);
//                debug(c+x);
                sq.push_back(make_pair(c, x));
                ans+=x*x;
                if (c<=lastcx) {
//                    cerr << "minus\n";
                    ans -= (lastcx-c)*(lastcx-c);
                }
            }
        }
        if (type == 2) {
            c = c + x;
        }
    }
    cout << ans << endl;
}
