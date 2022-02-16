#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <sstream>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll n,k;

ll test(ll cur){
    ll ans = 0;
    if (k==0) {
        ans = 1;
        ll j = 1;
        while (j<=cur) {
            ll a = (cur /(10*j));
            ans += a * j;
            j*=10;
        }
        return ans;
    }
    
    if (cur % 10 >= k) {
        ans++;
    }
//    debug(ans);
    ll i = 1;  //1.2.3.4.5
    ll j = 10;  //1.10.100.1000  處理位數
    while (j<=cur) {
        ll a = (cur %(10*j))/j;
//        debug(a);
//        debug(j);
        ans += a*i*(j/10);
//        debug(ans);
        if (a>k) {
            ans+=j;
        }else if(a == k){
//            cerr << "rrr" << endl;
            ans+=(cur%j)+1;
        }
        i++;
        j*=10;
//        debug(ans);
    }
    return ans;
}

int main() {_
    k = 0;
    debug(test(3048));
    return 0;
    cin >> n >> k;
//    for (n = 1; n<=10; n++) {
//        for (k = 0; k < 10; k++) {
            
        
    
    ll L = 0;
    ll R = 1e13;
    while (R-L>1) {
        ll M = (L+R)/2;
        ll tf = test(M);
        if (tf>=n) {
            R = M;
        }else{
            L = M + 1;
        }
    }
    ll num;
    ll nowmany = test(L);
    if (nowmany>=n) {
        num = L;
    }else{
        num = R;
        nowmany = test(R);
    }
    
    ll ans = 1;
    stringstream ss;
    ss << num;
    string a;
    ss >> a;
    ll temp = test(num-1);
    for (int i = 0; i < a.size(); i++) {
        ans++;
        if (a[i]=='0'+k) {
            temp++;
        }
        if (temp>=n) {
            break;
        }
    }
    num--;
    ll bits = 1;
    ll thepow = 9;
    while (num > thepow) {
        num -= thepow;
        ans += bits*thepow;
        thepow*=10;
        bits++;
    }
    ans += num*bits;
//    printf("n=%lld,k=%lld,ans=%lld\n",n,k,ans);
  cout << ans << endl;
//        }}
    return 0;
}
