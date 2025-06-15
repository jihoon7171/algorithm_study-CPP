#include<vector>
#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
int n;
vector<int>number;
int main(){
    cin >> n; 
    number.resize(n);
    for(int i=0;i<n;i++){
        cin>>number[i];
    }
    vector<pair<int, int>>dp(n,{-1,1});
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(number[i] > number[j]){
                if(dp[i].second < dp[j].second+1){
                    dp[i].second = dp[j].second+1;
                    dp[i].first = j;
                }
            }
        }
    }
    int maxthing = -1;
    for (const auto& p : dp) {
        maxthing = max(maxthing, p.second);
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(dp[i].second == maxthing){
            count = i;
            break;
        }
    }
    vector<int>answer;
    cout<<maxthing;
    cout<<"\n";
    // for(int i=0;i<n;i++){
    //     cout<<dp[i].first<<" "<<dp[i].second<<"\n";
    // }
    while(count !=-1){
        answer.push_back(number[count]);
        count = dp[count].first;
    }
    for(int i=answer.size()-1;i>=0;i--){
        cout<<answer[i]<<" ";
    }

    
}