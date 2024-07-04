#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;


int main() {_
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);
    int n,q;
    cin>>n>>q;
    vector <int> a(n);
    vector <int> pos[n];
    for (int i = 0; i < n ; i++ ) {
        cin >> a[i] ;
        pos[a[i]].push_back(i);
    }
    for (int times = 0; times < q; times++) {
        int l,r;
        cin >> l >> r;
        l -= 1;
        r -= 1;
        int k = 14;
        bool tf = 1;
        for (int i = 0 ; i < k; i++ ) {
            int temp = uniform_int_distribution<int>(l, r)(rng);
            // cout << "eee" << temp << endl;
            int cur = a[temp];
            auto left = lower_bound(pos[cur].begin(), pos[cur].end(), l);
            auto right = upper_bound(pos[cur].begin(), pos[cur].end(), r);
            int temp3 = right - left;
            if (temp3 >(r-l+1)/2){
                //cout << temp3 <<"rrr\n";
                cout << cur << endl;
                tf = 0;
                break;
            }
        }
        if(tf)cout << 0 << endl;
    }
    
    return 0;
}

