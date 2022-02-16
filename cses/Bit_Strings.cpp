#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <climits>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1e9+7;
ll pow(ll a,ll n){
    ll ans = 1;
    for (ll i = 1; i <= n; i*=2) {
        if(n&i)ans=ans*a%mod;
        a = (a*a)%mod;
    }
    return ans;
}

int main() {_
    int n;
    cin >> n;
    cout << pow(2, n) << endl;
    return 0;
}
