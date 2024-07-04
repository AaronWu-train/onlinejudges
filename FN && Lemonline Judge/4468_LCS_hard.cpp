#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;


int main() {_
    int n;
    cin >> n;
    vector<int>dp;
    vector<int>arr(n+1);
    for (int i = 1; i<=n; i++) {
        int temp;
        cin >> temp;
        arr[temp] = i;
    }
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(dp.empty()||arr[temp]>dp.back()){
            dp.push_back(arr[temp]);
        }else{
            auto it = lower_bound(dp.begin(), dp.end(), arr[temp]);
            *it = arr[temp];
        }
    }
    cout << dp.size()<<endl;
    return 0;
}
