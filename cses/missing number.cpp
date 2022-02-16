#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <climits>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    ll n,sum = 0;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        ll temp;
        cin >> temp;
        sum+=temp;
    }
    cout<<((1+n)*n/2)-sum<<endl;
    
    return 0;
}
