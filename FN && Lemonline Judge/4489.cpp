#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll mod = 1e9+7;
ll power(ll a,ll n){
    ll ans = 1;
    for (; n; n/=2) {
        if(n&1)ans = (a*ans)%mod;
        a = (a * a)%mod;
    }
    return ans;
}
int main() {_
    ll m,n;
    cin >> n >> m;
    ll arr[n+4];
    arr[0] = 1;
    for(int i = 1;i <= n+1;i++){
        arr[i] = (arr[i-1]*i)%mod;
    }
    cout << ((arr[n]*power(arr[m], mod - 2))%mod)*power(arr[n-m], mod - 2)%mod<< endl;
    return 0;
}
