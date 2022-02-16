#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <utility>
#define ll long long int
#define pii pair<int,int>
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main() {_
    string a,b;
    int n,m;
    cin >> n >> m >> a >> b;
    pii dp[n+1][m+1]; //l0 r1 斜2 return 3
    for (int i = 0; i<=n; i++) {
        dp[0][i]=make_pair(0,3);
        dp[i][0]=make_pair(0,3);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (dp[i][j-1].first<dp[i-1][j].first) {
                dp[i][j]=make_pair(dp[i-1][j].first, <#_T2 &&__t2#>)
            }
            dp[i][j].first=max(dp[i][j-1].first,dp[i-1][j].first);
            
            if (a[i-1]==b[j-1]) {
                dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
            }

        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}

