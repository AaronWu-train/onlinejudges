#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#define ll long long int
#define debug(x) cerr<<"DEBUG: "<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void print(vector<vector<ll> > &a){
    for (auto &i : a) {
        for (auto &j : i) {
            cerr << j << " ";
        }
        cerr << endl;
    }
    return;
}

int main() {_
    ll n,m,q;
    cin >> n >> m >> q;
    vector<vector<ll>> a;
    vector<vector<ll>> b;
    for (ll i = 0; i < n; i++) {
        vector<ll>temp(m);
        for (ll j = 0; j < m; j++) {
            cin >> temp[j];
        }
        a.push_back(temp);
    }
    for (ll i = 0; i < n; i++) {
        vector<ll>temp(m);
        for (ll j = 0; j < m; j++) {
            cin >> temp[j];
        }
        b.push_back(temp);
    }
    
    for (ll count = 0; count < q; count++) {
        ll rax, ray, radx, rady, rbx, rby, rbdx, rbdy;
        cin >> rax >> ray >> radx >> rady;
        ll rasize,xasize = INT_MAX,yasize = INT_MAX;
        if (radx != 0) {
            xasize = (n-rax)/radx+1;
        }if (rady != 0) {
            yasize = (m-ray)/rady+1;
        }
        rasize=min(xasize,yasize) ;
        if (rasize == INT_MAX) {
            rasize = 1;
        }
//        debug(xasize);
//        debug(yasize);
//        debug(rasize);
        cin >> rbx >> rby >> rbdx >> rbdy;
        ll rbsize,xbsize = INT_MAX,ybsize = INT_MAX;
        if (rbdx != 0) {
            xbsize = ((n-rbx)/rbdx) + 1;
        }
        if (rbdy != 0) {
            ybsize = ((m-rby)/rbdy) + 1;
        }
        rbsize = min(xbsize,ybsize);
        if (rbsize == INT_MAX) {
            rbsize = 1;
        }
//        debug(xbsize);
//        debug(ybsize);
//        debug(rbsize);
        if (rasize == rbsize) {
            for (int i = 0; i < rasize; i++) {
                swap(a[rax+i*radx-1][ray+i*rady-1], b[rbx+i*rbdx-1][rby+i*rbdy-1]);
            }
        }
        print(a);
        print(b);
    }
    for (auto &i : a) {
        for (int j = 0;j<m-1;j++) {
            cout << i[j] <<" ";
        }
        cout << i[m-1];
        cout << endl;
    }
    //    cerr << endl;
    for (auto &i : b) {
        for (int j = 0;j<m-1;j++) {
            cout << i[j] <<" ";
        }
        cout << i[m-1];
        cout << endl;
    }
    
    return 0;
}


