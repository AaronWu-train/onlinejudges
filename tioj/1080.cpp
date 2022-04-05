#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <climits>
#include <bitset>
#include <cstdio>
#define ll long long int
#ifdef DEBUG
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#else
#define debug(x) 0
#define endl '\n'
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<ll> BIT;
vector<int> arr;
vector<int> v;
int n;

void modify(int x, int v){
	for (;x<=n; x+=x&(-x)){
		BIT[x]+=v;
	}
}


ll query(int q) {
    ll ret = 0;
    for(; q > 0; q -= q & -q){
        ret += BIT[q];
    }
    return ret;
}

inline int getid (int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int main() {_
    int count = 0;
	while (1){
        count++;
	  	cin >> n;
	  	if(n==0)break;
		BIT.clear();
		BIT.resize(n+1,0);
		arr.resize(n,0);
        for (auto &i : arr) {
            cin >> i;
        }
        
        v = arr;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()),v.end());
        
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            debug(getid(arr[i]));
            ans += i - query(getid(arr[i]));
            modify(getid(arr[i]), 1);
        }
        cout<<"Case #"<<count <<": "<< ans << endl;
	}
    
    
    
    
    
    
    
    
    return 0;
}

