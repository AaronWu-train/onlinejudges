#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <climits>
#include <bitset>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int n,m;
    cin >> n >> m;
    vector<int>railb(n);
    for(auto &i : railb)cin >> i;
    stack<int>sta;
    stack<int>temp;
    int left_front = 1;
    for (int i = 0; i < n; ++i) {
        while (left_front <= railb[i]) {
            sta.push(left_front++);
        }
        while (!sta.empty() && sta.top()!=railb[i] && temp.size() < m) {
            temp.push(sta.top());
            sta.pop();
        }
        if (sta.top()!=railb[i]) {
            cout << "no" << endl;
            return 0;
        }
        sta.pop();
        while (!temp.empty()) {
            sta.push(temp.top());
            temp.pop();
        }
    }
    cout << "yes" << endl;
    return 0;
}
