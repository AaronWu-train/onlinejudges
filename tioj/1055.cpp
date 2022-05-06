#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int a,b; 
    cin >> a >> b;
	if(a<b){
		for(int i = a ; i <= b; ++i) {
			for(int j = 0; j < i; ++j){
			cout << '*';
			}
		cout << endl;
		}
	}
	else{
		for(int i = a ; i >= b; --i) {
			for(int j = 0; j < i; ++j){
			cout << '*';
			}
		cout << endl;
		}
	}
    
    
    
    
    
    
    
    return 0;
}
