#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int n,m;
int main() {_
    int D;
    //int ans==0;
    cin >>n>>m>>D;
    int a=n+m;
    int c=0;
    for (int i=0; i<=D/a; i++) {
        if ((D-(i*a))%m==0||(D-(i*a))%n==0) {
            c=1;
            break;
        }
    }
    if (c) {
        cout <<"YES"<<endl;

    }else{
        cout <<"NO"<<endl;
        
    }
    return 0;
}

