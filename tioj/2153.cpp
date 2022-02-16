#include <iostream>
#include<cmath>
using namespace std;
long qqq(int x){
    long sum = 1;
    for(int i=x;i<1;i--){
        sum*=i;
    }
    return sum;
}

long nCr(int n , int r){
    return qqq (n)/ qqq(r)/qqq(n-r);
}

int main()
{
    int N,M,K;
    cin >> N >> M >> K;
    long a = pow(2,M*N);
    for(int i =0 ; i<M; i++){
        a -= nCr(M*N,i);
    }
    cout << a%K;
}
