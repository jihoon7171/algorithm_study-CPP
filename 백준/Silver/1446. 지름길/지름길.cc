#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<cstring>
#include<climits>
using namespace std;
vector<pair<int, int>>drive(13);
vector<int>sc(13);
vector<bool>visited(13);
int result=INT_MAX;
int n,d;
void dfs(int distance, int real){
    if(distance == d){
        result = min(result, real);
        return ;
    }

    for(int i=1;i<=n;i++){
        if(distance<d){
            if(distance<drive[i].first && drive[i].second<=d){
                if(drive[i].second - drive[i].first > sc[i]){
                int newreal = real;
                newreal += drive[i].first - distance;
                newreal += sc[i];
                dfs(drive[i].second, newreal);
                }else{
                    int newreal = real;
                    newreal += drive[i].second - distance;
                    dfs(drive[i].second, newreal);
                }
            }else if(distance == drive[i].first&& drive[i].second<=d ){
                if(drive[i].second - drive[i].first > sc[i]){
                int newreal = real;
                newreal += sc[i];
                dfs(drive[i].second, newreal);
                }else {
                    int newreal = real;
                    newreal += drive[i].second - distance;
                    dfs(drive[i].second, newreal);
                }
            }else {
                int newreal = real;
                newreal += d-distance;
                dfs(d, newreal);
            }
        }
    }
}


int main() {
    cin>>n>>d;
    drive.resize(n+1);
    sc.resize(n+1);
    visited.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>drive[i].first>>drive[i].second;
        cin>>sc[i];
    }
    dfs(0,0);
    cout<<result;

}