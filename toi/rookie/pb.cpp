#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main() {_
    int n;
    cin >>n;
    int t1 =1;
    int sum =0 ;
    for (int i=0; i<n; i++) {
        int t2 ;
        cin >> t2;
        if (t2>t1) {
            sum += (t2-t1)*3;
        }else{
            sum += (t1-t2)*2;
        }
        t1 = t2;
    }
    cout<<sum <<endl;
    return 0;
}

