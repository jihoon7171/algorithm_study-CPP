#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int a,b;
void dfs(int index, int count, vector<int>&as){
    if(count == b){
        for(int i=0;i<b;i++){
            cout<<as[i]<<" ";
        }
        cout<<"\n";
        return ;
    }

    for(int i=1;i<=a;i++){
        as[index] = i;
        dfs(index+1, count+1, as);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a>>b;
    vector<int>as(b);
    dfs(0,0, as);


}
