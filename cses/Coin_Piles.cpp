#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    ll t;
    cin >> t;
    while (t--) {
        ll a,b;
        cin >> a >> b;
        if (a<b) {
            swap(a, b);
        }
        if ((a-b)<=b &&(b-(a-b))%3==0) {
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    
    
    return 0;
}
