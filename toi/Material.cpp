#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;


int main() {_
    int n;
    cin >> n;
    vector<int>place(n+1);
    fill(place.begin(), place.end(), 0);
    for (int i = 1; i <=n; i++) {
        cin >> place[i];
    }
    int q = 1;
    cin >> q;
    vector<int>askl[q];
    vector<int>askr[q];
    for(int i = 0; i < q; i++){
        int l,r;
        cin >> l >>r;
        askl[l].push_back(i);
        askr[r].push_back(i);
    }
    vector<int>ans(q);
    fill(ans.begin(), ans.end(), 0);
    bitset <400001> used[q];
    vector<int>current;
    for(int i = 1;i <= n;i++){
        if((askl[i]).size()==0){
            for(auto k : askl[i]){
                current.push_back(k);
            }
        }
        for (auto k: current){
            if (!used[k][i]){
                used[k][i]=1;
                ans[k]++;
            }
        }
    }
    for (int k:ans) {
        cout << k << endl;
    }
    return 0;
}
