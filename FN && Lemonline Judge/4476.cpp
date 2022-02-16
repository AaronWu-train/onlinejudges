#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int t;
map <int,int> raman;
int main() {_
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        if (raman[a]!=0) {
            cout<<"Y "<<raman[a]<<endl;
            raman[a]+=1;
        }else{
            cout<<"N"<<endl;
            raman[a]+=1;
        }
    }
    
    
    return 0;
}

