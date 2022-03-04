#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int n;
    cin >> n;
    while (n!=0) {
        ll ans = 2;
        vector<ll>arr;
        ll maxn = LLONG_MIN;
        while (n--) {
            ll temp;
            cin >> temp;
            ans+=temp;
            maxn = max(maxn, temp);
            arr.push_back(temp);
        }
        ans+=maxn-1;
        cout << ans <<endl;
        cin >> n;
    }
    
    
    
    
    
    
    
    return 0;
}
