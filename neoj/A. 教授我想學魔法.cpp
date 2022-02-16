#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#define ll long long
#define debug(x) cerr << #x << " = " << (x) <<endl
#define _ ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);

using namespace std;
vector<int>runx = {0,0,0,-1,1};
vector<int>runy = {1,0,-1,0,0};
int room[1005][1005];

int main(){
    int t,n,m;
    cin >> t >> n >> m;
    int everyone = 600;
    multiset<int>abc;

//    for (int i = 0; i < n*m; i++){
//        abc.insert(0);
//    }

    for (int count = 0; count < t; count++) {
        int x,y,ans;
        cin >> x >> y >> ans;
        x++;
        y++;
        if (ans == 1) {
            for (int i = 0; i<5; i++) {
                if (x+runx[i]>0&&x+runx[i]<=n&&y+runy[i]>0&&y+runy[i]<=m) {
                    auto k = abc.find(room[x+runx[i]][y+runy[i]]);
                    room[x+runx[i]][y+runy[i]]+=1;
                    if (k!=abc.end()) {
                        abc.erase(k);
//                        abc.insert(room[x+runx[i]][y+runy[i]]);
                    }
                    abc.insert(room[x+runx[i]][y+runy[i]]);
                }
            }
        }else{
            for (int i = 0; i<5; i++) {
                if (x+runx[i]>0&&x+runx[i]<=n&&y+runy[i]>0&&y+runy[i]<=m) {
                    auto k = abc.find(room[x+runx[i]][y+runy[i]]);
                    room[x+runx[i]][y+runy[i]]-=1;
                    if (k!=abc.end()) {
                        abc.erase(k);
//                        abc.insert(room[x+runx[i]][y+runy[i]]);
                    }
                    abc.insert(room[x+runx[i]][y+runy[i]]);

                }
            }
            everyone+=1;
            //cerr << "haha100" << endl;
        }
        if (*(abc.rbegin())+everyone>1000||(everyone>1000&&abc.size()<n*m)) {
            everyone-=1;
            //cerr << "haha100" << endl;
        }
    }
    //debug(n*m);
    //debug(abc.size());
    //debug(everyone);
    int maxi = -1000000;
    vector<pair<int, int>>aaa;
    int cry = 0;
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= m; k++) {
            if (room[j][k]>maxi) {
                maxi = room[j][k];
                aaa.clear();
                aaa.push_back(make_pair(j-1, k-1));
            }else if(room[j][k]==maxi){
                aaa.push_back(make_pair(j-1, k-1));
            }
            if (room[j][k]+everyone<600) {
                cry++;
            }
        }
    }
    printf("%d %.1f\n",cry,(double)(maxi+everyone)/10.0);
    for (auto &i : aaa) {
        cout << i.first << " " << i.second << endl;
    }
    
    return 0;
}
