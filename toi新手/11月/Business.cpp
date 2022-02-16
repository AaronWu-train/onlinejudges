#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
vector<int> card;

int main() {_
    vector<int>a;
    int temp;
    cin >> temp;
    while(temp!=0){
        a.push_back(temp);
        cin >> temp;
    }
    int n;
    cin >> n;
    int k = a.size();
    for (int i = 0; i < n;i++){
        vector<int>b = a;
        for (int j = 0; j<k; j++) {
            if(j!=k-1){
                if (a[j] > a[j+1]&&j!=0) {
                    b[j+1] += a[j]*5/100;
                }
                if(a[j] > a[j+1]&&j==0){
                    b[j+1] += a[j]*0.1;
                }
            }
            if (j!=0) {
                if (a[j] > a[j-1] && j!=(k-1)) {
                    b[j-1] += a[j]*5/100;
                }
                if(a[j] > a[j-1] &&j==(k-1)){
                    b[j-1] += a[j]*0.1;
                }
            }
        }
        a = b;
    }
    for (int i = 0; i < k; i++) {
        cout << a[i] << " " ;
    }
    return 0;
}
