#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
int n,m;
int main(){
    ios::sync_with_stdio(false);
    int b;
    vector<vector<int>>space;
    cin>>n>>m>>b;
    space.resize(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>space[i][j];
        }
    }

    int maxh = INT_MIN; int minh = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maxh < space[i][j]){
                maxh = space[i][j];
            }
            if(minh > space[i][j]){
                minh = space[i][j];
            }
        }
    }

    int answer = INT_MAX; int answerh = 0;

    for(int i=minh;i<=maxh;i++){
        int time = 0;
        int block = b;
        
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                int diff = space[j][k] - i;
                if(diff < 0){
                    time  = time-diff;
                    block = block+diff;
                }else if(diff > 0){
                    time = time+diff*2;
                    block = block+diff;
                }
            }
        }
        if(block>=0){
            if(time < answer || ( time == answer && answerh < i)){
                answer = time;
                answerh = i;
            }
        }
    }
    cout<<answer<<" "<<answerh;

}
