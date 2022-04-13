#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <climits>
#include <bitset>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<pair<int, int>>G[100005];
void dfs(int index, vector<int>&dis,vector<bool>&visited){
    visited[index] = true;
    for (auto &cur : G[index]) {
        if (!visited[cur.first]) {
            dis[cur.first] = dis[index]+cur.second;
            dfs(cur.first, dis,visited);
        }
    }
    return;
}

int main() {_
    int n;
    while (1) {
        cin >> n;
        if(n==0) break;
        for (auto &i : G) i.clear();
        for (int i = 0; i<n-1; ++i) {
            int j,k,c;
            cin >> j >> k >> c;
            G[j].push_back(make_pair(k, c));
            G[k].push_back(make_pair(j, c));
        }
        vector<int>dis(n+5,0);
        vector<bool>visited(n+5,0);
        dfs(1,dis,visited);
        int maxind = max_element(dis.begin(), dis.end()) - dis.begin();
        vector<int>dis2(n+5,0);
        vector<bool>visited2(n+5,0);
        dfs(maxind, dis2, visited2);
        cout << *max_element(dis2.begin(), dis2.end()) << endl;

    }
    
    
    
    
    
    
    
    return 0;
}
