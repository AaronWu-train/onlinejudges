#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int t,n,m;
int main() {_
    cin >> t;
    while (t--) {
        cin >>m>>n;
        if (n-m==1)cout<<"Malantaŭen"<<endl;
        else cout<<"Unua movo"<<endl;
    }
    
    
    return 0;
}

