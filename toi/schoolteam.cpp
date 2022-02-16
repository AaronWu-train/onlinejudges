#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main() {_
    int n,m;
    cin >> n >> m;
    int boyTotal = 0;
    vector<int>gmb;
    for (int i = 0;i < (n + m) ; i++) {
        int b,g;
        cin >> b >> g;
        boyTotal+= b;
        gmb.push_back(g-b);
    }
    sort(gmb.begin(), gmb.end());
    for (int i = 0;i < m; i++) {
        boyTotal += gmb[i];
    }
    cout << boyTotal << endl;
    return 0;
}
