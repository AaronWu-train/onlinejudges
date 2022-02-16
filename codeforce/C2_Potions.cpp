#include <iostream>
#include <queue>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main() {_
    int n;
    cin >> n;
    ll sum=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    for (int i=0; i<n; i++) {
        sum+=a[i];
        pq.push(a[i]);
        if (sum<0) {
            sum-=pq.top();
            pq.pop();
        }
    }
    cout<<pq.size()<<endl;
    return 0;
}

