#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans += i;
    }
    cout << ans << endl;
    
    
    
    
    
    
    
    return 0;
}
