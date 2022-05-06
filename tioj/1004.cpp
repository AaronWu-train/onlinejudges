#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
using namespace std;
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main() {_
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans = (ans + 2)%i;
    }
    cout << ans+1 << endl;
    
    return 0;
}
