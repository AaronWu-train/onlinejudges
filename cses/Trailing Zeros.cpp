#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    ll n;
    cin >> n;
    ll fives = 0;
    while (n) {
        fives+=n/5;
        n/=5;
    }
    cout << fives <<endl;
    return 0;
}
