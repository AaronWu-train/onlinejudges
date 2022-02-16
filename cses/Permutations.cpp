#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << 1;
        return 0;
    }
    if (n<4) {
        cout <<"NO SOLUTION"<<endl;
        return 0;
    }
    vector<int>arr;
    int mid = n/2;
    for (int i = 1; i <=n/2; i++) {
        cout << (mid+i) << " ";
        cout << (i) << " ";
    }
    if (n&1) {
        cout << n;
    }
}
