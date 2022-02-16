#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <utility>
#include <queue>
#include <climits>
#include <stack>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main() {_
    int n,m;
    cin >> n >> m;
    vector<int>graph[n+1];
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector< pair<int, int> >visited(n+1,make_pair(INT_MAX, 0));
    queue<int>bfs;
    visited[1] = make_pair(1, 0);
    bfs.push(1);
    while (!bfs.empty()) {
        int cur = bfs.front();
        bfs.pop();
        for (auto i : graph[cur]) {
            if (visited[cur].first+1 < visited[i].first) {
                visited[i].second = cur;
                visited[i].first = visited[cur].first+1;
                bfs.push(i);
            }
        }
    }
    vector<int>mback;
    mback.push_back(visited[n].second);
    while (mback.back() != 1) {
        if (visited[mback.back()].second==0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        mback.push_back(visited[mback.back()].second);
    }
    
    cout << visited[n].first<<endl;
    for (auto p = mback.rbegin(); p != mback.rend();p++) {
        cout << *p << " ";
    }
    cout << n << endl;
    return 0;
}
