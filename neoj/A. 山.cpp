#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    ll n;
    cin >> n;
    vector<ll>arr(n+5);
    vector<ll>highs;
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
        if(i-1>=2){
            if(arr[i-1]>arr[i] && arr[i-1]>arr[i-2]){
                highs.push_back(i-1);
            }
        }
    }
    vector<ll>mountain(n+5,0);
    for (auto j : highs) {
        ll cur = arr[j];
        ll k = 1;
        while (j-k>=1&&j+k<=n) {
            if (arr[j+k]<cur && arr[j-k]<cur) {
                mountain[k]++;
                k++;
            }else{
                break;
            }
        }
    }
    
    for (ll i = 1; i <= n-1; i++) {
        cout << mountain[i] << " ";
    }
    cout << mountain[n] << endl;;
    return 0;
}
