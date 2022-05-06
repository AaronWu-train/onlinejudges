#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define ll long long int
#define endl '\n'
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    ll n, m;
    cin >> n >> m;
    ll dp[95][16] = {0};
    dp[1][0] = dp[1][1]=1;
    for (int i = 2; i <= m+1; ++i) {
        dp[i][0] = dp[i-1][0];
        for (int j = 1; j <= n; ++j) {
            dp[i][0]+=dp[i-1][j];
            dp[i][j] =dp[i-1][j-1];
        }
    }
//    for (int i = 0; i < m+5; ++i) {
//        cout << endl << i << " :";
//        for (auto num : dp[i]) {
//            cout << num << " ";
//        }
//    }
//    
    cout << dp[m+1][0] << endl;
    return 0;
}
