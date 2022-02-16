#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {_
    int n,maxw;
    cin >> n >> maxw;
    vector<int>value(n+3,0);
    vector<int>weight(n+3,0);
    vector<ll>dp(maxw+1);
    for (int i=1; i<=n; i++) {
        cin >> weight[i] >> value[i];
    }
    for(int i=1; i<=n; i++){
        for (int w=maxw; w>=i; w--) {
            if (w-weight[i]>=0) {
                dp[w] = max(dp[w], dp[ w-weight[i] ] +value[i]);

            }else{
                dp[w] = dp[w];

            }
        }
    }
    cout<<dp[maxw]<<endl;
    return 0;
}
