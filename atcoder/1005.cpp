#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <bitset>
#include <cmath>
#define ll long long int
#define endl '\n'
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

ll mgcd(ll a, ll b) {
    if (a==0) {
        return b;
    }
    return mgcd(b%a, a);
}

int main() {_
    ll n;
    cin >> n;
    while (n!=0) {
        vector<ll>arr(n);
        for(auto &i : arr)cin >> i;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; j++) {
//                debug(arr[i]);
//                debug(arr[j]);
//                debug(mgcd(arr[i], arr[j]));
                if (mgcd(arr[i], arr[j]) == 1) {
                    ans++;
                }
            }
        }
//        debug(ans);
        if (ans == 0) {
            cout << "No estimate for this data set."<<endl;
        }else{
            ll a = n*(n-1)/2;
//            debug(a);
            cout << fixed << setprecision(6) << sqrt((double)6*a/ans) << endl;
        }
        
        cin >> n;
    }
    return 0;
}
