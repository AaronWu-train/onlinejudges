#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long
#define debug(x) cerr << "DEBUG:"<<#x<<" = "<<(x)<<endl;
#define _ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;
int k = 0;
vector<pair<int, int>> ans;
void mymove(int n, int start, int end, int mid){
    if (n==1) {
        ans.push_back(make_pair(start, end));
        k++;
        return;
    }
    mymove(n-1,start,mid,end);
    ans.push_back(make_pair(start, end));
    k++;
    mymove(n-1,mid,end,start);
    return;
}
int main() {
    int n;
    cin >> n;
    mymove(n,1,3,2);
    cout << k << endl;
    for (auto i : ans) {
        cout << i.first << " " << i.second << endl;
    }
}
