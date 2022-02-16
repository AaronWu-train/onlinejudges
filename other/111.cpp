#include <iostream>
#include <string>
using namespace std;
int colla(int n){
	int m;
	if (n==1)return 1;
	if (n%2==1) m=colla(3*n+1);
	else m=colla(n/2);
	return max(n,m);
}

int main() {
    int n,m,k;
    int sum =0;
    cin >>n>>m>>k;
    for(int i=1;i<=n;i++){
    	sum += (colla(i)%m==k)?1:0;
	}
	cout<<sum<<endl;
	return 0;
}

