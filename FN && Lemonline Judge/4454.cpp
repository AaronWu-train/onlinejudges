#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#define _ ios::sync_with_stdio(false);cin.tie(0);
#define pll pair<long long,long long>
#define ll long long
using namespace std;
deque<pll> lr;   // first is l , sec is r
deque <pll> ask;
vector<pll> out;
long long n,q;
bool my_sort(pll a,pll b){
    return (a.first < b.first);
}
bool sec_sort(pll a,pll b){
    return (a.second < b.second);
}
int main() {_
    cin >> n;
    for (ll i=0; i<n; i++) {
        ll tem1,tem2;
        cin >> tem1 >> tem2;
        lr.push_back(make_pair(tem1, tem2));
    }
    sort(lr.begin(), lr.end(), my_sort);
    cin >>q;
    for (ll i =0; i<q; i++) {
        ll temp;
        cin >> temp;
        ask.push_back(make_pair(temp, i));
    }
    sort(ask.begin(), ask.end(), my_sort);
    ll count = 0;
    //bool in_range =0;
    ll l,r;
    r=999999;
    for (ll i=0; i<lr.size(); i++) {
        l=lr[i].first;
        deque<pll> left_thing;
        while (ask.front().first<l) {
            left_thing.push_back(ask.front());
            ask.pop_front();
        }
        sort(left_thing.begin(), left_thing.end(), sec_sort);
        for (pll a : left_thing){
            out.push_back(make_pair(max(a.first-r,l-a.first),a.second));
            count++;
        }
        left_thing={};
        r=lr[i].second;
        while (((l<=ask.front().first)&&(ask.front().first<=r))) {
            pll a=ask.front();
            out.push_back(a);
            count++;
        }
        if (count>=q) {
            break;
        }
    }
    sort(out.begin(), out.end(), sec_sort);
    for (auto b : out) {
        cout<<b.first<<endl;
    }
    
    return 0;
}


