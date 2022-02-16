#include <iostream>
using namespace std;
int main(){
    int t,n,m;
    cin >> t;
    while (t){
        cin >> n >> m;
        cout << (m/3)*(n/3) <<endl;
        t--;
    }
    return 0;
}
