#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int n;

int best(vector<int> current);
bitset<17>isfr[17];

int main() {_
    cin >> n;
    vector<int>a;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; i++) {
            bool temp;
            cin >> temp;
            
            isfr[i][j] = !temp;
        }
        a.push_back(i);
    }
    cout << best(a);
    return 0;
}
int best(vector<int>current){
    int k = current.size();
    if (k<2)return k;
    int maxnum =0 ;
    vector<int> newInput;
    
    for (int i = 0 ; i < k; i++) {
        newInput.clear();
        
        for (int j = 0; j < k; j++) {
            if(i!=j&&isfr[current[i]][current[j]]){
                newInput.push_back(j);
            }
        }
        if(newInput.size()<=maxnum)continue;
        maxnum = max(maxnum,best(newInput));
    }
    return maxnum + 1;
}
