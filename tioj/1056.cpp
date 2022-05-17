#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    string a[3];
    for (auto &i : a)cin >> i;
    int q=0;
    int w=0;
    for (auto i : a) {
        for (auto j : i) {
//            debug(j);
            if ( (j=='.')|(j=='O')|(j=='X') ) {
                if (j=='O') q++;
                if (j=='X') w++;
            }
            else {
                cout << "IMPOSSIBLE\n" ;
                return 0;
            }
        }
    }
    if (q-w==0 or q-w==1) {
        cout << "POSSIBLE\n" ;

    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
