#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
using namespace std;
int h,w;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>h>>w;
    vector<vector<int>>wall(h, vector<int>(w));

    for(int i=0;i<w;i++){
        int temp;
        cin>>temp;
        for(int j=0;j<temp;j++){
            wall[h-1-j][i] = 1;
        }
    }
    // for(int i=0;i<h;i++){
    //     for(int j=0;j<w;j++){
    //         cout<<wall[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int count=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(wall[i][j] == 1){
                if(j>0){
                    for(int k=j-1;k>=0;k--){
                        if(wall[i][k] == 1){
                            count+= j-k-1;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<count;


}