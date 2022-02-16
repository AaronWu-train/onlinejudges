#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define ll long long
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main() {_
    int n,k;
    cin >>n>>k;
    vector<int>s(n);
    vector<int>w(n);
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        s[i]=temp;
    }
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        w[i]=temp;
    }
    ll sum=0;
    int cru_k=0;
    int maxn = 0;
    for (int i=0; i<n; i++) {
        if(cru_k!=w[i]){
            sum+=maxn;
            cru_k=w[i];
            maxn=0;
        }
        maxn = max(maxn, s[i]);
    }
    sum+=maxn;
    cout<<sum<<endl;
    return 0;
}

