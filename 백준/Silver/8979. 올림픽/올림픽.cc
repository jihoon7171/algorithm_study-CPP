#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include<stack>
#include<set>
#include<queue>
#include<limits.h>
#include<queue>
using namespace std;

int w[3] = {3,2,1};

bool comp(vector<int>a, vector<int>b){
    return a[0] < b[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<vector<int>>medal(n, vector<int>(5));
    vector<int>score(n+1);
    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=0;j<4;j++){
            cin>>medal[i][j];
            if(j>0) temp += medal[i][j] * w[j-1];
        }
       medal[i][4] = temp;
    }
    
    sort(medal.begin(), medal.end(), comp);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<5;j++){
    //         cout<<medal[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int finding = medal[k-1][4];
    int mygold = medal[k-1][1];
    int mysilver = medal[k-1][2];
    int mycooper = medal[k-1][3];
    int count =1;
    for(int i=0;i<n;i++){
        if(medal[i][1] > mygold){
            count++;
        }else if(medal[i][1] == mygold){
            if(medal[i][2] > mysilver){
                count++;
            }else if(medal[i][2] == mysilver){
                if(medal[i][3] > mycooper){
                    count++;
                }
            }
        }
    }
    cout<<count;



}