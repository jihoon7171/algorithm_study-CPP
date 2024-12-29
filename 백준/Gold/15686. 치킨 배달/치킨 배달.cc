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
int n,m;
vector<vector<int>>ch;
vector<pair<int, int>>house;
vector<pair<int, int>>chicken;
vector<vector<int>>ans;
int answer = INT_MAX;

int cal(pair<int, int>a, pair<int, int>b){
    int answer =0;
    answer += abs(a.first - b.first);
    answer += abs(a.second- b.second);
    return answer;
}
void dfs(vector<bool>result, int index, int count){
    if(count == m){
        int temp=0;
        for(int i=0;i<house.size();i++){
            int nowmin = INT_MAX;
            for(int j=0;j<chicken.size();j++){
                if(result[j]){
                    nowmin = min(nowmin, cal(house[i], chicken[j]));
                }
            }
            temp += nowmin;
        }
            answer = min(answer, temp);
    }



    for(int i=index; i<chicken.size();i++){
        result[i] = true;
        dfs(result,i+1, count+1);
        result[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    ch.resize(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ch[i][j];
            if(ch[i][j] == 1){
                house.push_back({i,j});
            }
            if(ch[i][j] == 2){
                chicken.push_back({i,j});
            }
        }
    }


    //ans.resize(house.size(), vector<int>(chicken.size()));
    // for(int i=0;i<house.size();i++){
    //     for(int j=0;j<chicken.size();j++){
    //         int temp = cal(house[i], chicken[j]);
    //         ans[i][j] = temp;
    //     }
    // }
    vector<bool>result(chicken.size(), false);
    dfs(result, 0,0);


    cout<<answer;




    


 
}
