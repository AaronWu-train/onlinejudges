#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define left_child (2*index)
#define right_child (2*index+1)
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<ll>arr;
vector<ll>seq_tree;

inline void pull(int index){
    seq_tree[index] = min(seq_tree[left_child],seq_tree[right_child]);
}

void build(int l, int r, int index){
    if (l == r) {
        seq_tree[index] = arr[l];
        return;
    }
    
    int mid = l + (r-l)/2;
    build(l, mid, left_child);
    build(mid+1, r, right_child);
    pull(index);
}

void modify(int pos, int value, int l, int r, int index){
    if (l == r) {
        seq_tree[index] = value;
        return;
    }
    int mid = (l+r)/2;
    if (pos <= mid) modify(pos, value, l, mid, left_child);
    else modify(pos, value, mid+1, r, right_child);
    pull(index);
}

ll query(int ql, int qr, int l, int r, int index){
    if (ql == l && qr == r) {
        return seq_tree[index];
    }
    int mid = l + (r-l)/2;
    if (qr <= mid) return query(ql, qr, l, mid, left_child);
    else if(ql > mid) return query(ql, qr, mid+1, r, right_child);
    return min(query(ql, mid, l, mid, left_child), query(mid+1, qr, mid+1, r, right_child));
}

int main() {_
    
    int n,q;
    cin >> n >> q;
    seq_tree.resize(4*n);
    arr.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    
    build(1, n, 1);
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        switch (type) {
            case 1:
                int k, u;
                cin >> k >> u;
//                debug(1);
                modify(k, u, 1, n, 1);
                break;
            case 2:
                int a, b;
                cin >> a >> b;
                cout << query(a, b, 1, n, 1) << endl;
                break;
        }
//        cout << "debug:";
//        for (auto i : seq_tree) {
//            cout << i << " ";
//        }
//        cout << endl;
    }
    
    return 0;
}
