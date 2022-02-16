//
//  lib1044.h
//  onlinejudges
//
//  Created by Aaron Wu on 2021/11/26.
//

#ifndef lib1044_h
#define lib1044_h
using namespace std;
int k;
int Initialize(){
    int n;
    cin >> n >> k;
    return n;
}
int Guess(int Q){
    return (Q>=k);
}
void Report(int ans){
    if (ans == k)cout << "yes : " << ans << endl;
    else cout << "no : " << ans << endl;
}
#endif /* lib1044_h */
