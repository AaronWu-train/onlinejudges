#include <iostream>
#include <vector>
#include <string>
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {_
    int n;
    vector<int> s;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        s.push_back(a);
    }
    int m;
    vector<int> x;
    cin >> m;
    for (int i=0; i<m; i++) {
        int a;
        cin >> a;
        x.push_back(a);
    }
    
    
    long long minum = 1e15;
    for(int i=0;i<s.size();i++){
        long long sum =0;
        for (int j=0; j<x.size(); j++) {
            sum += abs(x[j]-s[(i+j)%n]);
        }
        minum=min(minum, sum);
    }
    cout<<minum;
    
    
    
    return 0;
}
