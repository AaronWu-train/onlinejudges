#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include "lib1044.h"
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int k;
int Initialize(){
    int n;
    cin >> n >> k;
    return n;
}
int Guess(int Q){
    return (Q>=k);
}
void Report(int ans){
    if (ans == k)cout << "yes : " << ans << endl;
    else cout << "no : " << ans << endl;
}
int main() {_
    int n = Initialize();
    int l = 1; int r = n;
    int mid = (l+r)/2;
    while (l < r) {
        mid = (l+r)/2;
        if (Guess(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    Report(r);
    return 0;
}
