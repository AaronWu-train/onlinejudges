#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main() {_
    int n;
    while(cin >> n){
        if (n == 0)return 0;;
        while (true) {
            stack<int>sta;
            queue<int>b;
            queue<int>a;
            int temp;
            for (int i = 0; i < n; i++) {
                a.push(i+1);
                cin >> temp;
                if (temp == 0)break;
                b.push(temp);
                
            }
            if(temp == 0)break;
            bool yn = 1;
            sta.push(0);
            while (!b.empty()) {
                int cur = b.front();
                while (cur != sta.top() ) {
                    if (a.empty()){
                        yn = 0;
                        cout << "No" << endl;
                        break;
                    }
                    sta.push(a.front());
                    a.pop();
                }
                sta.pop();
                b.pop();
                if (yn == 0)break;
            }
            if (yn == 1)cout << "Yes" <<endl;
        }
        cout << endl;
        
    }
    
    return 0;
}
