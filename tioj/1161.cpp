#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <utility>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define All(x) begin(x),end(x)
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<pair<int,int>>arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(All(arr));
        priority_queue<int, vector<int>,less<int>> pq;
        for (int i = 0; i < k; ++i) {
            pq.push(arr[i].second);
        }
    }
   
    
    return 0;
}
