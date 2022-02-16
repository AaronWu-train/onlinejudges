#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    ll n;
    cin >> n;
    
    ll ans = (1+n)*n/2;
    if (ans&1) {
        cout << "NO" << endl;
        return 0;
    }
    ans/=2;
    debug(ans);
    ll sum = 0;
    vector<ll>aset;
    vector<ll>bset;
    for (ll i = n; i>0; --i) {
        if (i+sum <= ans) {
            sum+=i;
            aset.push_back(i);
        }else{
            bset.push_back(i);
        }
    }
    
    if(sum==ans&&!aset.empty()&&!bset.empty()){
        cout << "YES\n" << aset.size()<<endl;
        for (ll i : aset) {
            cout << i << " ";
        }
        cout <<endl<<bset.size()<<endl;
        for (ll i : bset) {
            cout << i << " ";
        }
        cout << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
