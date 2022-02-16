#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;


int main() {_
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<int>dp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if(dp.empty()||arr[i]>dp.back()){
            dp.push_back(arr[i]);
        }else{
            auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout << dp.size() << endl;
    return 0;
}
