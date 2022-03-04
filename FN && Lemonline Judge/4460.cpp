#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;
int mod = 1e8+7;
vector<vector<int>> mmlt(vector<vector<int>>&a,vector<vector<int>>&b){
    vector<vector<int>> ret(3,vector<int>(3,0));
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return ret;
}

vector<vector<int>> pow(vector<vector<int>>& a,int n){
    
//    vector<vector<int>> ans = {{4,1,0},{2,4,2},{0,1,4}};

    vector<vector<int>> ans = {{1,0,0},{0,1,0},{0,0,1}};
//    n--;
    for (int i = 1; i <= n; i*=2) {
        if (i&n) {
            ans = mmlt(ans,a);
        }
        a = mmlt(a,a);
    }
    return ans;
}

signed main() {_
    int n;
    cin >> n;
    vector<vector<int>> a = {{4,1,0},{2,4,2},{0,1,4}};
    vector<vector<int>> b = pow(a,n);
    cout << b[0][0] << endl;
    return 0;
}

/*
 dp[i][max= dp[i-1][0]*4 + dp[i-1][1]*1 + dp[i-1][2]*0  //兩偶
 dp[i][1] = dp[i-1][0]*2 + dp[i-1][1]*4 + dp[i-1][2]*1  //一奇數一偶數
 dp[i][2] = dp[i-1][0]*0 + dp[i-1][1]*1 + dp[i-1][2]*4  //兩奇數
                 [[a],
                  [b],
                  [c]]
        [[4,1,0],
         [2,4,2],
         [0,1,4]]
 
 */

