#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

struct E{
    ll speed;
    int rate;
};
bool cmp(E a,E b){
    if (a.speed>b.speed) return 1;
    else if ( a.speed==b.speed)return a.rate>b.rate;
    else return 0;
}
int main() {_
    int T;
    cin >> T;
    while (T--) {
        int n,k;
        cin >> n >> k;
        vector<E>a(n);
        vector<ll>c(n);
        for (int i = 0; i < n; i ++) {
            cin >> a[i].speed >> a[i].rate;
        }
        for (int i = 0; i < n; i ++) {
            cin >> c[i];
        }
        sort(c.begin(), c.end(),greater());
        sort(a.begin(),a.end(),cmp);
        int l = 0;
        int r = 1e8+1;
        int mid = 0;
        int ans = 1e8+1;
        bool tf =0 ;
        while (l <= r) {
            mid = (l+r)/2;
            auto cur = a;
            for (int i = 0; i<cur.size();i++) {
                cur[i].speed += cur[i].rate*mid;
            }
            bool eee = 1;
            sort(cur.begin(), cur.end(), cmp);
            for (ll i = 0; i <= k; i ++) {
                ll j = n - k + i;
                if(cur[i].speed < c[j]){
                    eee = 0;
                    break;
                }
            }
            if(eee){
                r = mid-1;
                tf = 1;
                ans = min(ans,mid);
            }else{
                l=mid+1;
            }
        }
        if (tf) {
            cout << ans << endl;
        }else{
            cout << -1 <<endl;
        }
        
    }
    return 0;
}
