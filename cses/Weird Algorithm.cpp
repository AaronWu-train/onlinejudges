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
    while (n!=1) {
        cout << n <<" ";
        if(n%2==1)n = 3*n+1;
        else n = n/2;
    }
    cout<<n;
    
    return 0;
}
