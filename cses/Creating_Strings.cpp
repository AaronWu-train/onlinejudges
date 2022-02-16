#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    string a;
    cin >> a;
    sort(a.begin(), a.end());
    vector<string>ans;
    do{
        ans.push_back(a);
    }while(next_permutation(a.begin(), a.end()));
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i << endl;
    }
    
    
    return 0;
}
