#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main() {_
    int t;
    cin >>t;
    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        int sum =0;
        while (n!= 0) {
            sum += n%2;
            n /=2;
        }
        cout<<sum<<endl;
    }
    
    
    
    return 0;
}

