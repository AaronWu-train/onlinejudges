#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {_
    int n,m,x;
    cin >> n >> m >> x;
    vector<ll> boy(n,0);
    vector<ll> girl(m,0);
    for (int i=0; i<n; i++) {
        cin >> boy[i];
    }
    for(int i = 0; i < m; i++){
        cin >> girl[i];
    }
    sort(girl.begin(),girl.end());
    sort(boy.begin(),boy.end());
    int ans = 0;
    ll ptrb = 0;
    ll ptrg = 0;
    while (ptrb < n && ptrg < m) {
        if ((boy[ptrb] >= girl[ptrg] -x)&&(girl[ptrg] + x >= boy[ptrb])){
            ans++;
            ptrb++;
            ptrg++;
            continue;
        }
        if(girl[ptrg] -x >= boy[ptrb])ptrb ++;
        else ptrg ++;
    }
    cout << ans << endl;
    return 0;
}
