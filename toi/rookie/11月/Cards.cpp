#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
vector<int> card;
void wash(){
    queue<int>b;
    queue<int>c;
    for (int i = 0 ; i < card.size()/2;i++){
        b.push(card[i]);
        c.push(card[card.size()/2+i]);
    }
    for(int i = 0 ; i < card.size()/2;i++){
        card[2*i]=b.front();
        card[2*i+1]=c.front();
        b.pop();
        c.pop();
    }
}

int main() {_
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >>temp;
        card.push_back(temp);
    }
    for (int i = 0; i < m; i++ ) {
        wash();
    }
    for (int i = 0; i < n; i++) {
        cout << card[i] ;
        if (i!=n-1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
