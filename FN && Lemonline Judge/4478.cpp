#include <iostream>
#include <vector>
#include <string>
#define ll long long
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
vector<ll>a;
const ll mod =1e9+7;
int main() {_
    ll q,n;
    cin >>q;
    a.push_back(1);
    for (ll i=1; i<=1e6; i++) {
        a.push_back((i*a[i-1])%mod);
    }
    while (q--) {
        cin>>n;
        cout<<a[n-1]<<endl;
    }
    return 0;
}

