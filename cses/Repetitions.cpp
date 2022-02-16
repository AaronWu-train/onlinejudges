#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
#define debug(x) cerr<<"DEBUG: " << #x << " = " << (x) << endl
using namespace std;


int main(){
    string a;
    cin >> a;
    char curchar = '0';
    int ans = 0;
    int cur = 0;
    for (char i : a) {
        if (i == curchar) {
            cur++;
//            cerr << "www"<<endl;
        }else{
//            debug(i);
            ans = max(ans, cur);
            cur = 1;
            curchar = i;
//            debug(curchar);
        }
    }
    ans = max(ans, cur);
    cout << ans << endl;
    
    return 0;
}
