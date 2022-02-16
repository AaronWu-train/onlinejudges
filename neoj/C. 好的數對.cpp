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


int main() {_
    ll n,c;
    cin >> n >> c;
    vector<int>arr(n+5);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int tf[15] = {0};
    int ptrl = 1;
    int ptrr = 1;
    ll ans = 0;
    int count = 0;
    while (count < c&&ptrr<=n) {
        if (tf[arr[ptrr]]<=0) {
            count++;
        }
        tf[arr[ptrr]]++;
        if (count >= c) {
            break;
        }
        ptrr++;
    }

    ans+=n-ptrr+1;
//    debug(ptrl);
//    debug(ptrr);
    ptrl++;
    for (; ptrl <= n; ptrl++) {
//        debug(ptrl);
        tf[arr[ptrl-1]]--;
        while (tf[arr[ptrl-1]]<=0 && ptrr < n) {
            ptrr++;
            tf[arr[ptrr]]++;
//            debug(ptrr);
        }
        if (ptrr>=n&&tf[arr[ptrl-1]]<=0) {
            break;
        }
//        cerr << "add\n";
        ans += n-ptrr+1;
//        debug(ans);
    }
    
    cout << ans << endl;
    return 0;
}
