#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int n;
    cin >> n;
    vector<ll>arr(n);
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    ll last = 0;
    ll ans = 0;
    for (auto& i : arr) {
        if (i < last) {
            ll a = i;
            i = last ;
            ans += i-a;
        }
        last = i;
    }
    cout << ans << endl;
    return 0;
}
