#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
int n,m;
int answer = 0;
vector<string>word;
vector<bool>used(27);
vector<int>study;

void checking(){
    int now = 0 ;
    for(int i=0;i<word.size();i++){
        bool flag = true;
        for(int j=0;j<word[i].size();j++){
            int qw = word[i][j]-'a';
            if(!used[qw]){
                flag = false;
                break;
            }
        }
        if(flag){
            now++;
        }
    }
    answer = max(now, answer);
    return;
}


void dfs(int count, int idx){
    if(count == 0){
        checking();
        return;
    }

    for(int i=idx;i<26;i++){
        if(!used[i]){
            used[i] = true;
            dfs(count-1, i+1);
            used[i] = false;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string qw;
        cin>>qw;
        word.push_back(qw.substr(4, qw.length()-8));
    }
    if(m<5){
        cout<<0;
        return 0;
    }
    string temp = "antic";
    for(int i=0;i<temp.size();i++){
        int a = temp[i] - 'a';
        used[a] = true;
    }
    int count = m-5;
    // for(int i=0;i<n;i++){
    //     string nn = word[i];
    //     for(int j=0;j<nn.size();j++){
    //         int q = nn[j] - 'a';
    //         if(!used[q] ){
    //             study.push_back(q);
    //         }
    //     }
    // }
    dfs(count,0);
    cout<<answer;


}