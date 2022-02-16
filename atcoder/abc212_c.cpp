#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <climits>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main() {_
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i<n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i<m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int pta=0,ptb=0;
    int ans=INT_MAX;
   // cout<<INT_MAX<<endl<<LONG_MAX<<endl;
    while (pta<n&&ptb<m) {
        ans = min(ans, abs(a[pta]-b[ptb]));
        if (a[pta]<b[ptb]) {
            pta++;
        }else{
            ptb++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

