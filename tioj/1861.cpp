#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define int long long
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
//priority_queue<int, vector<int>, greater<int> > pq;
signed main() {_
    int n;
    while (cin>>n) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i=0; i<n; i++) {
            int temp;
            cin>>temp;
            pq.push(temp);
        }
        int sum=0;
        while (pq.size()>1) {
            int a,b;
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            sum+=a+b;
            pq.push(a+b);
        }
        cout<<sum<<endl;
        
    }
    
    
    
    return 0;
}

