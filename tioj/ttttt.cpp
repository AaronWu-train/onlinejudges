//
//  main.cpp
//  TIOJ-1603
//
//  Created by Elaine Chen on 2022/9/19.
//

#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

vector<int> a;
vector<int> tree, tree2;

void build(int l, int r, int now){
    if(l == r){
        tree[now] = a[l];
        tree2[now] = a[l];
        return;
    }
    
    build(l, (l+r)/2, 2*now);
    
    build((l+r)/2 +1, r, 2*now +1);
    
    tree[now]= min(tree[2*now], tree[2*now+1]);
    tree2[now]= max(tree2[2*now], tree2[2*now+1]);

}




int findMin(int ql, int qr, int l, int r, int now){
    
    if(l== ql && r==qr) return tree[now];
    
    if(qr<= (l+r)/2)
    {
        return findMin(ql, qr, l,(l+r)/2, 2*now);
    }
    else if(ql > (l+r)/2)
    {
        return findMin(ql, qr, (l+r)/2 +1 ,r, 2*now +1);
    }
    else{
        return min(findMin((l+r)/2 +1, qr, (l+r)/2 +1,r, 2*now +1), findMin(ql, (l+r)/2, l, (l+r)/2, 2*now));
    }
    
}

int findMax(int ql, int qr, int l, int r, int now){
    
    if(l== ql && r==qr) return tree2[now];
    
    
    
    if(qr<= (l+r)/2)
    {
        return findMax(ql, qr, l,(l+r)/2, 2*now);
    }
    else if(ql > (l+r)/2)
    {
        return findMax(ql, qr, (l+r)/2 +1 ,r, 2*now +1);
    }
    else{
        return max(findMax((l+r)/2 +1, qr, (l+r)/2 +1,r, 2*now +1), findMax(ql, (l+r)/2, l, (l+r)/2, 2*now));
    }
    
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    tree.resize(4*n);
    tree2.resize(4*n);

    a.resize(n+1);
    
    for(int i = 1; i<=n; i++)
    {
        cin >> a[i];
    }
    
    build(1, n, 1);
    
    for(int i = 1; i<=m; i++)
    {
        int c, d;
        cin >> c >> d;
        
        cout << findMax(c, d, 1, n, 1)  - findMin(c, d, 1, n, 1) << endl;
        
    }
    
    
}


