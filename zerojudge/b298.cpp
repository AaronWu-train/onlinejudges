#include <iostream>
#include <vector>
using namespace std;

int func(int x,vector<int> &v,vector<int> &shit){
    if (shit[x]==1){
        return 1;
    }else if(v[x]==0){
        return 0 ;
    }else {return func(v[x],v,shit);}
}

int main(){
    int N,M,L;
    long Q;
    cin >> N >> M >> L >> Q;
    vector<int> v(N+1);
    for (long i =0;i<M;i++){
        int a,b;
        cin >> a >> b;
        v[b]=a;
    }
    
    vector<int> shit(N+1);
    for (long i=0; i<L; i++) {
        int x;
        cin >>x;
        shit[x]=1;
    }
    
    for (long i=0; i<Q; i++) {
        int x;
        cin >> x;
        int tf;
        tf = func(x, v, shit);
        if (tf==1){cout<<"TUIHUOOOOOO"<<endl;}
        else{cout<<"YA~~"<<endl;}
    }

    return 0;
}
