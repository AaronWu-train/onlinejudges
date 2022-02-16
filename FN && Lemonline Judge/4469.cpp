#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
ll dp[2][100005];

int main() {_
    int n,maxw;
    cin >> n >> maxw;
    //ll dp[n+2][100005];
    vector<int>value(n+3,0);
    vector<int>weight(n+3,0);
    //vector<vector<int> > dp(n+3,100005,0)
    for (int i=1; i<=n; i++) {
        cin >> weight[i] >> value[i];
    }
    for(int i=1; i<=n; i++){
        for (int w=0; w<=maxw; w++) {
            if (w-weight[i]>=0) {
                dp[i%2][w] = max(dp[(i-1)%2][w], dp[(i-1)%2][ w-weight[i] ] +value[i]);

            }else{
                dp[i%2][w] = dp[(i-1)%2][w];

            }
           // cout<<dp[i][w]<<endl;
        }
          //dp[0] = dp[1];
    }
    cout<<dp[(n)%2][maxw]<<endl;
    return 0;
}
