#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

//vector<vector<int> > dp;
int main() {_
    string a,b;
    int n,m;
    cin >> n >> m >> a >> b;
    int dp[n+1][m+1];
    for (int i =0; i<=n; i++) {
        dp[0][i]=0;
        dp[i][0]=0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if (a[i-1]==b[j-1]) {
                dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
            }

        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}

