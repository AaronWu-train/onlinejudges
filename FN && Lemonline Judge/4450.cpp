#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int n;
vector <pair<int,int> > s;
bool my_sort(pair<int, int>a,pair<int, int>b){
    return (a.first < b.first);
}
int main() {_
    cin>>n;
    for (int i=1; i<=n; i++){
        int temp;
        cin >> temp;
        s.push_back(make_pair(temp, i)) ;
    }
    sort(s.begin(), s.end(), my_sort);
    long long sum = s[0].second;
    for (int i=1; i<n; i++) {
        sum+=abs(s[i-1].second-s[i].second);
    }
    cout<<sum<<endl;
    return 0;
}
