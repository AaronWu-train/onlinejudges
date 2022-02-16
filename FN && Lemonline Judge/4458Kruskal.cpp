#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
struct E{
    int u,v,w;
};
struct cmp{
    bool operator()(E a,E b){
        return a.w<b.w;
    }
};

int f[4005];

int fa(int i){
    if (f[i]==i)return i;
    else{
        f[i] = fa(f[i]);
        return f[i];
    }
}
void join(int a,int b){
    f[fa(a)]=fa(b);
}

int main() {_
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n+5;i++){
        f[i]=i;
    }
    
    vector<E>lines;
    int u,v,w;
    for(int i=0;i<m;++i){
        cin >> u >> v >> w;
        lines.push_back({u,v,w});
    }
    cmp c;
    sort(lines.begin(), lines.end(), c);
    
    ll ans = 0;
    for (auto cur : lines) {
        if(fa(cur.u)!=fa(cur.v)){
            join(cur.u,cur.v);
            ans+=cur.w;
        }
    }
    cout << ans << endl;
    return 0;
}
