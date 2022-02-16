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
int h,w;
bitset<1005>arr[1005];
bitset<1005>visited[1005];
vector<int> x = {-1,0,0,1};
vector<int> y = {0,-1,1,0};

void dfs(int i,int j){
    debug(i);
    debug(j);
    //cerr << "\n";
    visited[i][j] = true;
    for (int t = 0; t < 4; ++t) {
        if (arr[i+y[t]][j+x[t]]&&!visited[i+y[t]][j+x[t]]){
            visited[i+y[t]][j+x[t]]=1;
            dfs(i+y[t], j+x[t]);
        }
    }
    return;
}

int main() {_
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 1005 ; i++) {
            arr[i].reset();
            visited[i].reset();
        }
        cin >> h >> w;
        for (int i = 1; i <= h; i++) {
            string temp;
            cin >> temp;
            for (int j = 0;j < w; j++) {
                arr[i][j+1] = (temp[j] == '.');
            }
        }
        int ans = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (!visited[i][j]&&arr[i][j]) {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
