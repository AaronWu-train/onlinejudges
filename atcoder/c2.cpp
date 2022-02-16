#include <iostream>
#include <vector>
#include <string>
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
vector<int>ahappy;
vector<int>bhappy;
vector<int>chappy;
vector<int>a;
vector<int>b;
vector<int>c;
int N;
int main() {_
    cin >> N;
    for (int i = 0 ; i<N; i++) {
        int aaa[3];
        cin >> aaa[0]>>aaa[1]>>aaa[2];
        a.push_back(aaa[0]);
        b.push_back(aaa[1]);
        c.push_back(aaa[2]);
    }
    ahappy.push_back(a[0]);
    bhappy.push_back(b[0]);
    chappy.push_back(c[0]);
    for (int i = 1; i<N; i++) {
        ahappy.push_back(a[i]+max(bhappy[i-1],chappy[i-1]));
        bhappy.push_back(b[i]+max(ahappy[i-1],chappy[i-1]));
        chappy.push_back(c[i]+max(ahappy[i-1],bhappy[i-1]));
    }
    cout<<max(max(ahappy[N-1],bhappy[N-1]),chappy[N-1])<<endl;
    return 0;
}
