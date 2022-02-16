#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define debug(x) cerr<<"DEBUG: " << #x << " ="<<(x)<<endl;
#define _ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main(){_
    string a,b;
    cin >> a >> b;
    int anum = 0;
    int bnum = 0;
    for(int i = 0;i<4;i++){
        if(a[i]==b[i]){
            anum++;
        }
    }
    for(int i = 0;i<4;i++){
        for(int j = 0; j < 4;++j){
            if(i==j)continue;
            if(a[i]==b[j]){
                bnum ++;
            }
        }
    }
    cout << anum << "A" << bnum << "B" << endl;
    return 0;
}


