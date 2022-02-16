#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int t;
    cin >> t;
    while (t--) {
        ll x,y;
        cin >> y >> x;
        if (x == y) {
            cout << x*x-x+1 << endl;
        }else if (x > y) {
            if (x&1) {
                cout << x*x-x+1+(x-y) << endl;
            }else{
                cout << x*x-x+1-(x-y) << endl;
            }
            
        }else{
            if (y&1) {
                cout << y*y-y+1-(y-x) << endl;
            }else{
                cout << y*y-y+1+(y-x) << endl;
            }
        }
        
        
        
        
        
    }
    
    
    return 0;
}
