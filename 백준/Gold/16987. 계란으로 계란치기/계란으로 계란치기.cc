#include <iostream>
#include<queue>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;
int n;
 // 내구도, 무게 , 내 내구도 - 상대 무게
void output(vector<pair<int, int>>egg){
    for(int i=0;i<egg.size();i++){
        cout<<egg[i].first<<" ";
    }
    cout<<"\n";
}
int answer = 0;
void dfs(int count, int nowegg, vector<pair<int, int>>egg){
    if(nowegg >=egg.size()){
        answer = max(count, answer);
        //output(egg);
        return ;
    }
    bool flag = false;
    if(egg[nowegg].first > 0){
        for(int i=0;i<egg.size();i++){
            if(egg[i].first >0 && nowegg != i){
                flag = true;
                egg[i].first -= egg[nowegg].second;
                egg[nowegg].first -= egg[i].second;
                int tempcount = count;
                if(egg[i].first <= 0){
                    tempcount++;        
                }
                if(egg[nowegg].first <=0){
                    tempcount++;
                }
                dfs(tempcount, nowegg+1, egg);
                egg[i].first += egg[nowegg].second;
                egg[nowegg].first += egg[i].second;
            }
        }
    }else {
        dfs(count, nowegg+1, egg);
        return;
    }
    if(!flag){
        dfs(count, nowegg+1, egg);
    }
}
int main() {

    cin>>n;
    vector<pair<int, int>>egg;
    egg.resize(n);
    for(int i=0;i<n;i++){
        cin>>egg[i].first>>egg[i].second;
    }
    dfs(0,0, egg);
    cout<<answer;





}
