#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>num(n+1, vector<int>(n+1,0));
    vector<vector<int>>basicnum(n+1, vector<int>(n+1,0));
    int sum = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int temp;
            cin>>temp;
            basicnum[i][j] = temp;
            num[i][j] = basicnum[i][j]+ num[i-1][j] + num[i][j-1] - num[i-1][j-1];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<num[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=0;i<m;i++){
        int x, y, xx, yy;
        cin>>x>>y>>xx>>yy;
        cout<<num[xx][yy] - (num[xx][y-1]+num[x-1][yy]) + num[x-1][y-1]<<"\n";

      
    }
}
