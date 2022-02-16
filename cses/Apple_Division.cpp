#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<int>apple;
ll k_for_debug = 0;
ll sum = 0;
ll find_min_sum(int i,ll cur_sum,int end_ind){
//    debug(i);
//    k_for_debug++;
//    debug(k_for_debug);
//    debug(cur_sum);
    if (i == end_ind) {
        return min(abs((sum-(cur_sum+apple[i]))-(cur_sum+apple[i])), abs((sum-cur_sum)-cur_sum));
    }
    return min(find_min_sum(i+1, cur_sum+apple[i], end_ind), find_min_sum(i+1, cur_sum, end_ind));
}
int main() {_
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        apple.push_back(temp);
        sum += temp;
    }
    cout << find_min_sum(0, 0, n-1) << endl;
    return 0;
}
