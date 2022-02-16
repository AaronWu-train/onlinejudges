#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int a[2005][2005];
const int mod = 1e9+7;
using namespace std;
int dp(int n,int m){
    if (a[n][m]!=0) {
        return a[n][m];
    }
    if (n==1||m==1) {
        a[n][m]=1;
        return 1;
    }else{
        a[n][m]=(dp(n-1, m)+dp(n, m-1))%mod;
        return (dp(n-1, m)+dp(n, m-1))%mod;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >>N>>M;
    cout <<dp(N, M)<<endl;
    
    
    return 0;
}

