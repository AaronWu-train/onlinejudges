#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {_
    int n,k;
    cin >> n >> k;
    vector<int>a(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    while (k--) {
        int l = 1,r = n;
        int mid;
        int ask;
        cin >>ask;
        while(l<=r){
            mid = (l+r)/2;
            if (a[mid]==ask) {
                cout << mid << endl;
                break;
            }else if (a[mid] < ask){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        if (a[mid]!=ask){cout << 0 << endl;}
    }
    
    return 0;
}
