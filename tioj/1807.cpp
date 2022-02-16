#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int m,n,a,b;
    map<int, vector<int>> mp;
    cin >> m >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        if (a==b||find(mp[a].begin(), mp[a].end(), b)!=mp[a].end()){
            cout<<"Yes\n";
            return 0;
            
        }
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    cout<<"yes\n";
    return 0;
}
