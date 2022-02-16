#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#define _ ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
//#define pll pair<long long,long long>

using namespace std;
map <ll,ll> lr;
long long n,q;

int main() {_
    cin >>n;
    for (ll i =0; i<n; i++) {
        ll temp1,temp2;
        cin >> temp1 >> temp2;
        lr [temp1]= temp2;
    }
    cin >> q;
    //start answering
    for (ll i =0; i<q; i++){
        ll a;
        cin >>a;
        auto it = lr.lower_bound(a);
       // auto endendend =(*lr.end()).second;
        //cout << (lr.end();
        if (it==lr.end()){
            it--;
            ll smaller_left=(*it).first;
            ll smaller_right=(*it).second;
            if (smaller_left<a&&a<=smaller_right) {
                cout << a << endl;
                lr.erase(it);
                lr[smaller_left]=a-1;
                if (a!=smaller_right)lr[a+1]=smaller_right;
                continue;
            }
            cout<<(*it).second<<endl;
            if ((*it).first==(*it).second){
                lr.erase(it);
            }else{
                (*it).second-=1;
            }
            continue;
        }
        auto bbb=lr.begin();
        if((*it).first==a||a<(*bbb).first){
            cout << (*it).first<<endl;
            if ( (*it).first == (*it).second) {
                lr.erase(it);
                continue;
            }else{
            lr[(*it).first+1]=(*it).second;
            lr.erase(it);
            continue;
            }
        }else{
            ll bigger_left = (*it).first;
            auto it2 = it;
            it--;
            
            ll smaller_left=(*it).first;
            ll smaller_right=(*it).second;
            if (smaller_left<a&&a<=smaller_right) {
                cout << a << endl;
                lr.erase(it);
                lr[smaller_left]=a-1;
                if (a!=smaller_right)lr[a+1]=smaller_right;
                continue;
            }else {   // in th middow of two range
                if (a-smaller_right >= bigger_left-a) {
                    cout << bigger_left << endl;
                    if((*it2).first!=(*it2).second){lr[(*it2).first+1]=(*it2).second;}
                    lr.erase(it2);
                    continue;
                }else{
                    cout << smaller_right << endl;
                    lr.erase(it);
                    if (smaller_left!=smaller_right) {
                        lr[smaller_left]=smaller_right-1;
                    }
                    continue;
                }
            }
        }
    }
    return 0;
}

