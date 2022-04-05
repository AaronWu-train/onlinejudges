#include <iostream>
using namespace std;
int main(){
  int m;
  cin >> m;
  while (m--){
	long long a, b ,c;
	
	cin >> a >> b >> c;
	cout << (b*b-4*a*c>=0?"Yes\n":"No\n");
  }
}
