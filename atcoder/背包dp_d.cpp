#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
ll dp[105][100005];
int main() {_
    int n,maxw;
    cin >> n >> maxw;
    //ll dp[n+5][maxw+5];
    vector<int>value(n+3,0);
    vector<int>weight(n+3,0);
    for (int i=1; i<=n; i++) {
        cin >> weight[i] >> value[i];
    }
    for(int i=1; i<=n; i++){
        for (int w=1; w<=maxw; w++) {
            if (w-weight[i]>=0) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][ w-weight[i] ] +value[i]);

            }else{
                dp[i][w] = dp[i-1][w];

            }
           // cout<<dp[i][w]<<endl;
        }
    }
    cout<<dp[n][maxw]<<endl;
    return 0;
}
