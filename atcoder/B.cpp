#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long destination(long a,long b){
    long c = a - b;
    return abs(c);
}

long findmincost(long i,long K,vector<long> &high,vector<long>&min_hi){
    vector <long> sum;
    long minum = 99999999999999999;
    for (long temp = i-1;temp >= i-K;temp--){
        sum.push_back(min_hi[temp]+destination(high[i], high[temp]));
    }
    for (auto temp : sum){
        minum = min(minum,temp);
    }
    return minum;

}

int main() {
    long N,K;
    cin >> N>>K;
    vector<long> high(N);
    for(long i =0;i<N;i++){cin>>high.at(i);}
    vector<long>min_hi(N);
    min_hi[0]=0;
    min_hi[1]=destination(high[1], high[0]);
    for (long i=2;i<N;i++){
        min_hi[i]= findmincost(i, min(i,K) ,high, min_hi);
    }
    cout << min_hi[N-1]<<endl;
    return 0;
}
